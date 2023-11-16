/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:06:21 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:02:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new->content == NULL)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
		tmp = ft_lstnew(f(lst->content));
		if (!tmp->content)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
	}
	return (new);
}
