/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execve_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:41 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 14:32:06 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	spec(int signal)
{
	(void)signal;
}

static void	check_sig(int pid)
{
	signal(SIGINT, spec);
	waitpid(pid, &g_ret_value, 0);
	if (g_ret_value == 2)
	{
		printf("\n");
		g_ret_value = 130;
	}
	else if (g_ret_value == 131)
		printf("Quit (core dumped)\n");
	else
		g_ret_value = WEXITSTATUS(g_ret_value);
	signal(SIGINT, sig_handler);
}

static void	dup_fd(t_cmds *cmd, t_datas *data)
{
	if (cmd->infile)
		if (!ft_fd_infile(cmd))
			ft_exit_childs(data, 1);
	if (cmd->outfile)
		if (!ft_fd_outfile(cmd))
			ft_exit_childs(data, 1);
}

void	simple_command(t_cmds *cmd, t_datas *data, t_list_env **env_sh)
{
	int	pid;

	pid = 0;
	if (ft_builtins_parent(env_sh, cmd, data))
		return ;
	pid = fork();
	if (pid < 0)
		printf("Could not create a sub process\n");
	if (!pid)
	{
		signal(SIGQUIT, SIG_DFL);
		dup_fd(cmd, data);
		if (ft_builtins(env_sh, cmd, data))
			ft_exit_childs(data, 0);
		else if (execve(cmd->cmd, cmd->args, data->env) == -1)
			ft_exit_childs(data, 126);
		ft_exit_childs(data, 0);
	}
	else
		check_sig(pid);
	return ;
}
