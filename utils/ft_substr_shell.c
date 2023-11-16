/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:49:11 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:15 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_substr_shell(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	t = malloc(sizeof(char) * (len + 1));
	t[len] = 0;
	if (!t)
		return (0);
	while (s[start] && i < len)
		t[i++] = s[start++];
	return (t);
}
