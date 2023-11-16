/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:17:53 by argomez           #+#    #+#             */
/*   Updated: 2022/12/26 18:52:35 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_in_env(char *to_find, char **env)
{
	char	*find;
	int		index;
	int		size;
	int		size_to_find;

	to_find = multi_join(2, "", to_find, "=");
	size_to_find = ft_strlen(to_find);
	index = 0;
	while (env[index])
	{
		if (!ft_strncmp(to_find, env[index], size_to_find))
		{
			free(to_find);
			size = ft_strlen(env[index] + size_to_find);
			find = malloc(sizeof(char) * (size + 1));
			if (!find)
				return (NULL);
			find[size] = '\0';
			ft_strlcpy(find, env[index] + size_to_find, size + 1);
			return (find);
		}
		index++;
	}
	free(to_find);
	return (NULL);
}

int	is_in_env(char *to_find, char **env)
{
	int		index;
	int		size_to_find;

	to_find = multi_join(2, "", to_find, "=");
	size_to_find = ft_strlen(to_find);
	index = 0;
	while (env[index])
	{
		if (!ft_strncmp(to_find, env[index], size_to_find))
		{
			free(to_find);
			return (1);
		}
		index++;
	}
	free(to_find);
	return (0);
}
