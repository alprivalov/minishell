/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:46:39 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:46:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_add_char(t_list_env **env_sh, char *vars, char *value_vars)
{
	t_list_env	*tmp;
	char		*str_out;

	tmp = (*env_sh);
	while (tmp)
	{
		if (tmp && ft_strcmp(tmp->vars, vars) == -1)
		{
			if (tmp->vars_value)
			{
				str_out = ft_strjoin_sh(tmp->vars_value, value_vars);
				free(tmp->vars_value);
				tmp->vars_value = ft_strdup(str_out);
				free(tmp->vars_all);
				tmp->vars_all = multi_join(3, "3", vars, "=", str_out);
			}
			else
			{
				free(tmp->vars_all);
				tmp->vars_all = multi_join(3, NULL, vars, "=", value_vars);
				tmp->vars_value = ft_strdup(value_vars);
			}
		}
		tmp = tmp->next;
	}
}
