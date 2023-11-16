/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:02:02 by argomez           #+#    #+#             */
/*   Updated: 2022/08/15 12:44:31 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	*result;
	size_t	i;
	size_t	size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	result = malloc(sizeof(char) * (size + 3));
	result[size + 2] = '\0';
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
		result[i++] = *str++;
	free(str - size);
	result[i++] = c;
	result[i] = 0;
	return (result);
}
