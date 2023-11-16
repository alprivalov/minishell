/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:49:09 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:16 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	ft_strlen_sh(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_sh(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen_sh(s1) + ft_strlen_sh(s2) + 1));
	if (!tab)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
	}
	j = i - 1;
	i = -1;
	if (s2)
		while (s2[++i])
			tab[++j] = s2[i];
	tab[j + 1] = 0;
	return (tab);
}
