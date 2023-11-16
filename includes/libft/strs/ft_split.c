/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:58:04 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 17:01:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	size_t	ft_strnbr(char const *s, char c)
{
	size_t	strnbr;
	size_t	index;
	int		state;

	strnbr = 0;
	index = 0;
	state = 0;
	if (s[index] != c && s[index] != '\0')
		strnbr++;
	while (s[index] == c && s[index] != '\0')
		index++;
	if (s[index] == '\0')
		state = 1;
	while (s[index] && s[index] != '\0')
	{
		if (index > 0 && s[index - 1] == c && s[index] != c)
			strnbr++;
		index++;
	}
	if (state == 0 && strnbr == 0)
		strnbr++;
	return (strnbr);
}

static size_t	ft_index(char const *s, char c, size_t index, size_t strnbr)
{
	size_t	i;

	i = 0;
	while (s[index] == c && s[index] != '\0')
		index++;
	while (i < strnbr && s[index] != '\0')
	{
		while (s[index] != c)
			index++;
		i++;
		while (s[index] == c)
			index++;
	}
	return (index);
}

static char	*ft_findstr(char const *s, char c, size_t strnbr)
{
	size_t	i;
	size_t	index;
	size_t	count;
	char	*str;

	index = 0;
	index = ft_index(s, c, index, strnbr);
	count = 0;
	index++;
	while (s[index - 1] != c && s[index - 1] != '\0')
	{
		count++;
		index++;
	}
	if (count == 0)
		count++;
	str = ft_calloc(sizeof(char), count + 2);
	if (!str)
		return (NULL);
	index -= count + 1;
	i = 0;
	while (count-- > 0)
		str[i++] = s[index++];
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	strnbr;
	size_t	index;

	if (!s)
		return (tab = ft_calloc(sizeof(char), 1));
	else
		strnbr = ft_strnbr(s, c);
	tab = ft_calloc(sizeof(char *), strnbr + 2);
	if (!tab)
		return (NULL);
	index = 0;
	while (index < strnbr)
	{
		str = ft_findstr(s, c, index);
		tab[index] = str;
		index++;
	}
	return (tab);
}
