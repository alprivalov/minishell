/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:02:13 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:06:22 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	size_t	index;

	if (!s)
		return (NULL);
	t = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!t)
		return (NULL);
	index = 0;
	while (*s)
	{
		t[index] = (f)(index, *s);
		s++;
		index++;
	}
	return ((char *)t);
}
