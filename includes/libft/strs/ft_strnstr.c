/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:41:03 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:06:39 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tlen;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			tlen = len;
			while (little[j] != '\0' && tlen > 0 && big[i + j] == little[j])
			{
				j++;
				tlen--;
			}
			if (j == ft_strlen(little))
				return ((char *)&big[i]);
		}
		len--;
		i++;
	}
	return (NULL);
}
