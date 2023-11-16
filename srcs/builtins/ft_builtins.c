/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:24 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:51:04 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_builtins_parent(t_list_env **env_sh, t_cmds *cmd, t_datas *data)
{
	if (ft_strcmp(cmd->cmd, "cd") == -1)
		ft_cd(cmd, data);
	else if (ft_strcmp(cmd->cmd, "export") == -1)
		ft_export(cmd, env_sh);
	else if (ft_strcmp(cmd->cmd, "unset") == -1)
		ft_unset(cmd, data);
	else if (ft_strcmp(cmd->cmd, "exit") == -1)
		ft_exit(cmd, data);
	else
		return (0);
	return (1);
}

int	ft_builtins(t_list_env **env_sh, t_cmds *cmd, t_datas *data)
{
	if (ft_strcmp(cmd->args[0], "echo") == -1)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->args[0], "env") == -1)
		ft_printf_list_env(cmd, env_sh);
	else if (ft_strcmp(cmd->args[0], "pwd") == -1)
		ft_pwd(data);
	else if (ft_strcmp(cmd->args[0], "cd") == -1)
		ft_cd(cmd, data);
	else if (ft_strcmp(cmd->args[0], "export") == -1)
		ft_export(cmd, env_sh);
	else if (ft_strcmp(cmd->args[0], "unset") == -1)
		ft_unset(cmd, data);
	else if (ft_strcmp(cmd->args[0], "exit") == -1 && data->nb_pipe == 0)
		ft_exit(cmd, data);
	else
		return (0);
	return (1);
}

void	ft_exit_childs(t_datas *data, int exit_code)
{
	close(0);
	close(1);
	ft_free_env_list(data->env_sh);
	ft_free(data, 0);
	exit (exit_code);
}

void	ft_print_wrong_files(t_cmds *cmd, int i, t_datas *data)
{
	if (i == 0)
	{
		ft_printf_fd(2, "bash: %s: No such file or directory\n", cmd->cmd);
		g_ret_value = 127;
	}
	else if (i == 1)
	{
		ft_printf_fd(2, "bash: %s: Permission denied\n", cmd->cmd);
		g_ret_value = 126;
	}
	else if (i == 2)
	{
		ft_printf_fd(2, "bash: %s: Is a directory\n", cmd->cmd);
		g_ret_value = 127;
	}
	else if (i == 3)
	{
		if (data->path_env)
			ft_printf_fd(2, "bash: %s: command not found\n", cmd->cmd);
		else
			ft_printf_fd(2, "bash: %s: No such file or directory\n", cmd->cmd);
		g_ret_value = 127;
	}
}

void	ft_arg_builtins(t_cmds *cmd, t_list_sh *list
		, t_list_env **env_sh, t_datas *data)
{
	t_list_sh	*tmp;

	tmp = list;
	if (cmd->cmd && cmd->args[0][0] && get_path(cmd, data->path_env, data))
	{
		if (data->nb_pipe != 0)
		{
			data->pid[data->index_pid] = ft_command(cmd, data, env_sh);
			data->index_pid++;
		}
		else
			simple_command(cmd, data, env_sh);
	}
	else if (cmd->cmd)
	{
		if (tmp && tmp->type_vars == D_REDIR_L)
			return ;
	}
	else
		g_ret_value = 0;
}
