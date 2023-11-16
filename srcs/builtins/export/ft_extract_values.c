/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:00 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:54:30 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_vars_exports(char	*str)
{
	int		i;
	char	*str_out;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	str_out = ft_substr_shell(str, 0, i);
	if (!str_out)
		return (NULL);
	return (str_out);
}

char	*ft_value_vars(char	*str, char *vars_export)
{
	char	*str_out;
	int		len_vars;

	if (!str || !vars_export)
		return (NULL);
	len_vars = ft_strlen(vars_export);
	if (str[len_vars] && str[len_vars] == '+')
		len_vars++;
	if (str[len_vars] && str[len_vars] == '=')
		len_vars++;
	str_out = ft_substr_shell(str, len_vars, ft_strlen(str) - len_vars);
	if (!str_out)
		return (NULL);
	return (str_out);
}
