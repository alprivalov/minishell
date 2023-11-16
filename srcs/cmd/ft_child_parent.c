/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:35 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 14:41:55 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_child(t_cmds *cmd, t_datas *datas, t_list_env **env_sh)
{
	signal(SIGQUIT, SIG_DFL);
	if (cmd->cmd_number == 0)
		first_command(cmd, datas, env_sh);
	else if (cmd->cmd_number < datas->nb_pipe)
		middle_command(cmd, datas, env_sh);
	else if (cmd->cmd_number == datas->nb_pipe)
		last_command(cmd, datas, env_sh);
}
