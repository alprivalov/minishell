/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_d_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:35 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list_sh	*ft_pars_dquotes(t_pars *vars, t_datas *data, t_list_sh *list)
{
	if (data->input_str[vars->pars_i] && data->input_str[vars->pars_i] == '\"')
	{
		vars->pars_start = vars->pars_i;
		vars->pars_i++;
		while (data->input_str[vars->pars_i]
			&& data->input_str[vars->pars_i] != '\"')
			vars->pars_i++;
		vars->type = DOUBLE_QUOTE;
		list = ft_write_list(data->input_str, list, vars);
		vars->type = 0;
	}
	return (list);
}
