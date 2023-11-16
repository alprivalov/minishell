/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:10:45 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:04:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*t;
	const unsigned char	*u;

	if (!dest && !src)
		return (NULL);
	t = dest;
	u = src;
	if (src > dest)
		while (n-- > 0)
			*t++ = *u++;
	else
		while (n-- > 0)
			t[n] = u[n];
	return (dest);
}
