/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:50 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 14:47:27 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_space(t_list_sh **tmp)
{
	int	i;

	i = -1;
	while ((*tmp)->content[++i])
		if ((*tmp)->content[i] != ' ')
			return (0);
	return (1);
}

int	ft_check_join(t_list_sh **tmp)
{
	if ((*tmp) && ((*tmp)->type_vars == SINGLE_QUOTE
			|| (*tmp)->type_vars == DOUBLE_QUOTE)
		&& (*tmp)->type_vars != SPACE && (*tmp)->next->type_vars != SPACE)
		return (1);
	else if ((*tmp)->next
		&& ((*tmp)->next->content[0] != '|'
			&& (*tmp)->next->content[0] != '>'
			&& (*tmp)->next->content[0] != '<'
			&& (*tmp)->content[0] != '|'
			&& (*tmp)->content[0] != '>'
			&& (*tmp)->content[0] != '<'
			&& (*tmp)->next->type_vars != SPACE
			&& (*tmp)->type_vars != SPACE))
		return (1);
	return (0);
}

t_list_sh	*ft_join_list(t_list_sh *list, t_list_sh *new_list)
{
	t_list_sh	*tmp;
	t_list_sh	*tmp_new;

	tmp = list;
	tmp_new = new_list;
	while (tmp)
	{
		while (tmp->next && ft_check_join(&tmp))
		{
			tmp->next->content = ft_strjoin_frees(tmp->content,
					tmp->next->content, 'S');
			tmp = tmp->next;
		}
		if (tmp_new == NULL)
			tmp_new = ft_d_lstnew(tmp->content, tmp->type_vars);
		else
			ft_d_lstadd_back(tmp_new,
				ft_d_lstnew(tmp->content, tmp->type_vars));
		tmp = tmp->next;
	}
	return (tmp_new);
}
