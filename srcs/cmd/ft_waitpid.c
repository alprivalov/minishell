/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:40 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:28 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_waitpid(t_cmds *cmd, t_datas *data)
{
	int	i;

	(void)cmd;
	i = 0;
	while (data->pid && data->pid[i])
	{
		signal(SIGINT, spec);
		waitpid(data->pid[i], &g_ret_value, 0);
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
		i++;
	}
}
