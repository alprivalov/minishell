/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:31:22 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:01:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp != NULL)
	{
		tmp2 = tmp2->next;
		del(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
