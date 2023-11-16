/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:38 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:53:23 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_fd(t_datas *datas)
{
	int	i;

	i = 0;
	if (!datas->fd_pipe)
		return ;
	while (i < datas->nb_pipe + 1)
	{
		if (datas->fd_pipe[i][0] > 0)
			close(datas->fd_pipe[i][0]);
		if (datas->fd_pipe[i][1] > 0)
			close(datas->fd_pipe[i][1]);
		i++;
	}
}

void	ft_exec_cmd(t_datas *data, t_list_sh *list, t_list_env *env_sh)
{
	int		i;
	t_cmds	*cmd;

	i = 0;
	cmd = data->cmds;
	while (i < data->nb_pipe + 1)
	{
		ft_arg_builtins(&cmd[i], list, &env_sh, data);
		i++;
	}
	ft_close_fd(data);
	ft_waitpid(cmd, data);
}
