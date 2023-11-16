/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:41:24 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:04:43 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *s, size_t n)
{
	unsigned char		*t;
	const unsigned char	*u;

	if (!s && !dest)
		return (dest);
	t = dest;
	u = s;
	while (n-- > 0)
		*t++ = *u++;
	return (dest);
}
