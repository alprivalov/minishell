/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:04:06 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:04:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	size_t				t;

	t = 0;
	t1 = s1;
	t2 = s2;
	if (n <= 0)
		return (0);
	while (t1[t] == t2[t] && t < n - 1)
		t++;
	return (t1[t] - t2[t]);
}
