/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_type_redir_l.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:00 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	type_redir_l_d(t_list_sh **tmp)
{
	(*tmp)->type_vars = D_REDIR_L;
	if ((*tmp)->next && !(size_t)ft_strncmp((*tmp)->next->content, " ",
			(size_t)ft_strlen((*tmp)->content)))
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = WHITE_SPACE;
		if ((*tmp)->next)
		{
			(*tmp) = (*tmp)->next;
			(*tmp)->type_vars = D_REDIR_L;
		}
	}
	else if ((*tmp)->next)
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = D_REDIR_L;
	}
}

void	type_redir_l(t_list_sh **tmp)
{
	(*tmp)->type_vars = S_REDIR_L;
	if ((*tmp)->next && !(size_t)ft_strncmp((*tmp)->next->content, " ",
			(size_t)ft_strlen((*tmp)->content)))
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = WHITE_SPACE;
		if ((*tmp)->next)
		{
			(*tmp) = (*tmp)->next;
			(*tmp)->type_vars = S_REDIR_L;
		}
	}
	else if ((*tmp)->next)
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = S_REDIR_L;
	}
}
