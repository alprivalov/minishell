/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_ow_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:46:41 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:46:47 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exp_ow_char(t_list_env **env_sh, char *value, char *vars)
{
	t_list_env	*tmp;

	tmp = (*env_sh);
	while (tmp)
	{
		if (tmp && ft_strcmp(tmp->vars, vars) == -1)
		{
			if (tmp && ft_strcmp(tmp->vars, vars) == -1)
			{
				free(tmp->vars_value);
				if (value == 0)
					tmp->vars_value = ft_strdup("\0");
				else
					tmp->vars_value = ft_strdup(value);
				free(tmp->vars_all);
				tmp->vars_all = multi_join(3, "", vars, "=", value);
			}
		}
		tmp = tmp->next;
	}
}
