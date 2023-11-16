/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_s_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:54 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 13:56:20 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list_sh	*ft_pars_squotes(t_pars *vars, t_datas *data, t_list_sh *list)
{
	if (data->input_str[vars->pars_i] && data->input_str[vars->pars_i] == '\'')
	{
		vars->pars_i++;
		vars->pars_start = vars->pars_i;
		while (data->input_str[vars->pars_i]
			&& data->input_str[vars->pars_i] != '\'')
			vars->pars_i++;
		vars->type = SINGLE_QUOTE;
		list = ft_write_list(data->input_str, list, vars);
		vars->type = 0;
	}
	return (list);
}
