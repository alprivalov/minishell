/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list_sh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:49:06 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list_sh	*ft_d_lst(char *str, t_pars	*vars)
{
	t_list_sh	*new;

	new = malloc(sizeof(t_list_sh));
	if (!new)
		return (NULL);
	new->content = ft_strdup(str);
	new->next = NULL;
	if (vars->type == WHITE_SPACE)
		new->type_vars = SPACE;
	else if (vars->type == SINGLE_QUOTE)
		new->type_vars = SINGLE_QUOTE;
	else if (vars->type == DOUBLE_QUOTE)
		new->type_vars = DOUBLE_QUOTE;
	else
		new->type_vars = 0;
	return (new);
}

t_list_sh	*ft_d_lstnew(char *str, int type_vars)
{
	t_list_sh	*new;

	new = malloc(sizeof(t_list_sh));
	if (!new)
		return (NULL);
	new->type_vars = type_vars;
	new->content = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_list_sh	*ft_d_lstlast(t_list_sh *lst)
{
	if (lst)
	{
		while (lst -> next)
			lst = lst -> next;
	}
	return (lst);
}

void	ft_d_lstadd_back(t_list_sh *list, t_list_sh *new)
{
	t_list_sh	*temp;

	if (list)
	{
		temp = ft_d_lstlast(list);
		temp -> next = new;
		new -> preview = temp;
	}
}
