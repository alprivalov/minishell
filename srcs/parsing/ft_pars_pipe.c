/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:52 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list_sh	*ft_pars_pipe(t_pars *vars, t_datas *data, t_list_sh *list)
{
	if (data->input_str[vars->pars_i] && data->input_str[vars->pars_i] == '|')
	{
		while (data->input_str[vars->pars_i + 1]
			&& ft_is_space(data->input_str[vars->pars_i + 1]))
			vars->pars_i++;
		if (data->input_str[vars->pars_i + 1] == '|')
			ft_prinft_error(vars, data->input_str[vars->pars_i + 1]);
		vars->type = PIPE;
		list = ft_write_list(data->input_str, list, vars);
		vars->type = 0;
	}
	return (list);
}
