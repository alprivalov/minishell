/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:49:34 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:04:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t;
	unsigned char		c2;
	size_t				i;

	c2 = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (NULL);
	t = s;
	while (i < n)
	{
		if (t[i] == c2)
			return ((char *)(t + i));
		i++;
	}
	return (NULL);
}
