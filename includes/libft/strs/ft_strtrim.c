/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:18:20 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:06:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	check_index(char const *s1, char const *set, int option)
{
	size_t	i;

	if (option == 0)
	{
		i = 0;
		while (check_char(s1[i], set) == 1)
			i++;
	}
	else
	{
		i = ft_strlen(s1) - 1;
		while (check_char(s1[i], set) == 1)
			i--;
	}
	return (i);
}

static size_t	check_validity(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (check_char(s1[i], set) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (check_validity(s1, set) == 0)
		return (s2 = ft_calloc(sizeof(char), 1));
	start = check_index(s1, set, 0);
	end = check_index(s1, set, 1);
	s2 = ft_calloc(sizeof(char), (end - start + 2));
	if (!s2)
		return (NULL);
	i = 0;
	while (start < end + 1)
	{
		s2[i] = s1[start];
		start++;
		i++;
	}
	return (s2);
}
