/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_mid_last_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:39 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:47:03 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	first_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh)
{
	int	fd_in;
	int	fd_out;

	fd_in = 0;
	fd_out = 0;
	if (cmd->infile)
		if (!ft_if_data_cmd_in(fd_in, cmd))
			ft_exit_childs(datas, 1);
	if (cmd->outfile)
	{
		if (!ft_if_data_cmd_out(fd_out, cmd))
			ft_exit_childs(datas, 1);
	}
	else
		if (dup2(datas->fd_pipe[cmd->cmd_number][1], STDOUT_FILENO) == -1)
			exit (printf("First : Could not duplicate the FD\n"));
	close_redirection_fd(fd_in, fd_out, cmd);
	exec_cmd_builtins(cmd, datas, env_sh);
}

void	middle_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh)
{
	int	fd_in;
	int	fd_out;

	fd_in = 0;
	fd_out = 0;
	if (cmd->infile)
	{
		if (!ft_if_data_cmd_in(fd_in, cmd))
			ft_exit_childs(datas, 1);
	}
	else
		if (dup2(datas->fd_pipe[cmd->cmd_number - 1][0], STDIN_FILENO) == -1)
			exit (printf("Middle : Could not duplicate the FD\n"));
	close(datas->fd_pipe[cmd->cmd_number - 1][0]);
	if (cmd->outfile)
	{
		if (ft_if_data_cmd_out(fd_out, cmd) == 0)
			ft_exit_childs(datas, 1);
	}
	else
		if (dup2(datas->fd_pipe[cmd->cmd_number][1], STDOUT_FILENO) == -1)
			exit (printf("Middle : Could not duplicate the FD\n"));
	close_redirection_fd(fd_in, fd_out, cmd);
	exec_cmd_builtins(cmd, datas, env_sh);
}

void	last_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh)
{
	int	fd_in;
	int	fd_out;

	fd_in = 0;
	fd_out = 0;
	if (cmd->infile)
	{
		if (!ft_if_data_cmd_in(fd_in, cmd))
			ft_exit_childs(datas, 1);
	}
	else
		if (dup2(datas->fd_pipe[cmd->cmd_number - 1][0], STDIN_FILENO) == -1)
			exit (printf("Last : Could not duplicate the FD\n"));
	if (cmd->outfile)
	{
		if (!ft_if_data_cmd_out(fd_out, cmd))
			ft_exit_childs(datas, 1);
	}
	close_redirection_fd(fd_in, fd_out, cmd);
	exec_cmd_builtins(cmd, datas, env_sh);
}
