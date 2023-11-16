/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:10:48 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:07:05 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	t = ft_calloc(sizeof(char), (len + 1));
	if (!t)
		return (0);
	while (s[start] && i < len)
		t[i++] = s[start++];
	return (t);
}
