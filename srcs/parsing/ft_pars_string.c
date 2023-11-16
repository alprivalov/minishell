/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:55 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_special(t_datas *data, t_pars *vars)
{
	if (data->input_str[vars->pars_i] == '\''
		|| data->input_str[vars->pars_i] == '\"'
		|| data->input_str[vars->pars_i] == '|'
		|| data->input_str[vars->pars_i] == '>'
		|| data->input_str[vars->pars_i] == '<'
		|| data->input_str[vars->pars_i] == '$')
		return (1);
	return (0);
}

t_list_sh	*ft_pars_string(t_pars *vars, t_datas *data, t_list_sh *list)
{
	if (data->input_str[vars->pars_i]
		&& !ft_is_space(data->input_str[vars->pars_i])
		&& !ft_is_special(data, vars))
	{
		vars->pars_start = vars->pars_i;
		while (data->input_str[vars->pars_i]
			&& !ft_is_space(data->input_str[vars->pars_i])
			&& !ft_is_special(data, vars) && data->input_str[vars->pars_i])
			vars->pars_i++;
		list = ft_write_list(data->input_str, list, vars);
	}
	return (list);
}
