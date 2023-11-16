/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:24:02 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:06:47 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*t;

	t = s;
	while (*s != '\0')
		s++;
	while (*s != (unsigned char)c)
	{
		if (s == t)
			return (NULL);
		s--;
	}
	return ((char *)s);
}
