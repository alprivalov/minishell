/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:17:23 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:06:06 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t size)
{
	size_t	count;
	size_t	count_2;

	count = 0;
	count_2 = 0;
	while (src[count_2] != '\0')
		count_2++;
	if (size < 1)
		return (count_2);
	while (src[count] != '\0' && count < size - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (count_2);
}
