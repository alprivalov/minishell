/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:04 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:47 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_fd_pipe(t_datas *data)
{
	int	i;

	if (!data->fd_pipe)
		return ;
	i = 0;
	while (i < data->nb_pipe + 1)
	{
		if (data->fd_pipe[i])
			free(data->fd_pipe[i]);
		i++;
	}
	free(data->fd_pipe);
}

void	free_path_env(t_datas *data)
{
	int	i;

	if (!data->path_env)
		return ;
	i = 0;
	while (data->path_env[i])
	{
		free(data->path_env[i]);
		i++;
	}
	free(data->path_env);
	data->path_env = NULL;
}

void	free_cmd(t_cmds *cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	if (cmd->infile)
		free(cmd->infile);
	cmd->infile = NULL;
	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = NULL;
	if (cmd && cmd->args)
	{
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
		cmd->args = NULL;
	}
}

void	ft_free_cmds(t_datas *data)
{
	int	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		free_cmd(&data->cmds[i]);
		i++;
	}
	free(data->cmds);
}
