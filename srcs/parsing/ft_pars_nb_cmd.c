/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_nb_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:52 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:35 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	list_next_cmd(t_list_sh **list)
{
	while ((*list) && (*list)->type_vars != PIPE)
	{
		if ((*list) && (*list)->next)
			(*list) = (*list)->next;
		else
			break ;
	}
}
