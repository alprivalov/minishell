/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:39 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:47:07 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_stat(char *str)
{
	struct stat	sb;

	stat(str, &sb);
	if (sb.st_mode & S_IFDIR)
	{
		ft_printf_fd(2, "bash: %s: Is a directory\n", str);
		return (0);
	}
	if (!(sb.st_mode & S_IRWXU))
	{
		ft_printf_fd(2, "bash: %s: Permission denied\n", str);
		return (0);
	}
	return (1);
}

void	close_redirection_fd(int fd_in, int fd_out, t_cmds *cmd)
{
	(void)cmd;
	if (fd_in)
		close(fd_in);
	if (fd_out)
		close(fd_out);
}

int	ft_if_data_cmd_in(int fd_in, t_cmds *cmd)
{
	if (access(cmd->infile, F_OK) == 0)
		if (!ft_check_stat(cmd->infile))
			return (0);
	fd_in = open(cmd->infile, O_RDONLY);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		return (0);
	return (1);
}

int	ft_if_data_cmd_out(int fd_out, t_cmds *cmd)
{
	if (access(cmd->outfile, F_OK) == 0)
		if (!ft_check_stat(cmd->outfile))
			return (0);
	if (cmd->type_outfile == D_REDIR_R)
		fd_out = open(cmd->outfile, O_RDWR | O_APPEND);
	else
		fd_out = open(cmd->outfile, O_RDWR | O_TRUNC);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		return (0);
	return (1);
}
