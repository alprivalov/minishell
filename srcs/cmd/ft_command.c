/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:37 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:51:07 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_cmd_builtins(t_cmds *cmd, t_datas *datas, t_list_env **env_sh)
{
	if (ft_builtins(env_sh, cmd, datas))
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		ft_close_fd(datas);
		ft_exit_childs(datas, 0);
	}
	ft_close_fd(datas);
	if (execve(cmd->cmd, cmd->args, datas->env) == -1)
	{
		close(STDOUT_FILENO);
		printf("First : Could not execute the command\n");
		ft_exit_childs(datas, 127);
	}
}

int	ft_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh)
{
	int			pid;

	pid = 0;
	pid = fork();
	if (pid < 0)
		return (0);
	if (!pid)
		ft_child(cmd, datas, env_sh);
	return (pid);
}
