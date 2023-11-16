/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:05 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:47:06 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_char_bad(char c)
{
	if ((c < 'a' || c > 'z')
		&& (c < 'A' || c > 'Z') && c != '_')
		return (1);
	return (0);
}

char	*ft_init_before_str(char *str_in, int i)
{
	char	*str_out;

	str_out = malloc(sizeof(char) * (i + 1));
	if (!str_out)
		return (NULL);
	ft_strlcpy(str_out, str_in, i);
	ft_strlcat(str_out, "=\0", i + 1);
	return (str_out);
}

char	*ft_init_export_no_plus(char *str)
{
	char	*str_out;
	int		i;

	str_out = NULL;
	i = 0;
	if (ft_char_bad(str[i]))
		return (NULL);
	while (str[i] && str[i] != '=')
	{
		if (ft_char_bad(str[i]) && (str[i] < '0' || str[i] > '9'))
			return (NULL);
		i++;
	}
	if (str[i] != '=')
		return (ft_strdup(str));
	i++;
	str_out = multi_join(2, "1-2", ft_substr_shell(str, 0, i),
			ft_substr_shell(str, i, ft_strlen(str) - i));
	return (str_out);
}

char	*ft_init_export_plus(char *str)
{
	char	*str_out;
	int		i;

	i = 0;
	if (ft_char_bad(str[i]))
		return (NULL);
	while (str[i] && str[i] != '=')
	{
		if (ft_char_bad(str[i]) && (str[i] < '0' || str[i] > '9')
			&& str[i] != '+')
			return (NULL);
		if (str[i] == '+' && str[i + 1] && str[i + 1] != '=')
			return (NULL);
		i++;
	}
	if (str[i] != '=')
		return (ft_strdup(str));
	str_out = multi_join(2, "1-2", ft_init_before_str(str, i),
			ft_substr_shell(str, i + 1, ft_strlen(str) - (i + 1)));
	return (str_out);
}
