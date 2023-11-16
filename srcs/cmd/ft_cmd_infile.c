/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_infile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:36 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:30:38 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_check_stat(char *str)
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

int	ft_fd_infile(t_cmds *cmd)
{
	int	fd;

	if (access(cmd->infile, F_OK) == 0)
	{
		if (!ft_check_stat(cmd->infile))
			return (0);
	}
	else
		return (0);
	fd = open(cmd->infile, O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		g_ret_value = 1;
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_fd_outfile(t_cmds *cmd)
{
	int	fd;

	if (access(cmd->outfile, F_OK) == 0)
	{
		if (!ft_check_stat(cmd->outfile))
			return (0);
	}
	if (cmd->type_outfile == S_REDIR_R)
		fd = open(cmd->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		fd = open(cmd->outfile, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
