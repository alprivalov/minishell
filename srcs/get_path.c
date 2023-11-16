/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:07 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 19:46:43 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_if_builtins(t_cmds *cmd, t_datas *data)
{
	(void)data;
	if ((ft_strcmp(cmd->cmd, "$?") == -1)
		|| (ft_strcmp(cmd->cmd, "echo") == -1)
		|| (ft_strcmp(cmd->cmd, "env") == -1)
		|| (ft_strcmp(cmd->cmd, "pwd") == -1)
		|| (ft_strcmp(cmd->cmd, "cd") == -1)
		|| (ft_strcmp(cmd->cmd, "export") == -1)
		|| (ft_strcmp(cmd->cmd, "unset") == -1)
		|| (ft_strcmp(cmd->cmd, "exit") == -1))
		return (1);
	return (0);
}

int	ft_path_exist(t_cmds *cmd, char **paths, char *command)
{
	char	*temp_path;
	int		index;

	index = 0;
	if (!paths)
		return (0);
	while (paths[index])
	{
		temp_path = ft_strjoin_sh(paths[index], command);
		if (access(temp_path, F_OK) == 0)
		{
			free(cmd->args[0]);
			cmd->args[0] = temp_path;
			cmd->cmd = temp_path;
			free(command);
			return (1);
		}
		free(temp_path);
		temp_path = NULL;
		index++;
	}
	return (0);
}

static int	check_fd(char *command, t_datas *data, t_cmds *cmd)
{
	struct stat	sb;

	if (ft_strchrc(command, '/') == 1)
	{
		if (cmd->cmd[0] == '/' || cmd->cmd[0] == '.')
		{
			if (stat(cmd->cmd, &sb) == -1)
			{
				ft_print_wrong_files(cmd, 0, data);
				return (0);
			}
			else if (!(sb.st_mode & S_IXUSR))
				ft_print_wrong_files(cmd, 1, data);
			else if (S_ISDIR(sb.st_mode))
				ft_print_wrong_files(cmd, 2, data);
		}
		return (1);
	}
	return (2);
}

int	get_path(t_cmds *cmd, char **paths, t_datas *data)
{
	char		*command;
	int			status_file;

	if (data->fd_pipe && pipe(data->fd_pipe[cmd->cmd_number]) == -1)
	{
		ft_close_fd(data);
		exit(1);
	}
	command = cmd->cmd;
	if (!cmd->cmd)
		return (0);
	status_file = check_fd(command, data, cmd);
	if (status_file == 0)
		return (0);
	if (status_file == 1)
		return (1);
	if (ft_if_builtins(cmd, data))
		return (1);
	command = ft_strjoin_sh("/", cmd->cmd);
	if (ft_path_exist(cmd, paths, command))
		return (1);
	ft_print_wrong_files(cmd, 3, data);
	free(command);
	return (0);
}
