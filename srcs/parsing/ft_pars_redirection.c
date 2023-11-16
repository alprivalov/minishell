/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:53 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_redirection(t_datas *data, int i)
{
	if (data->input_str[i] == '>' || data->input_str[i] == '<')
		return (1);
	return (0);
}

t_list_sh	*ft_pars_redirection(t_pars *vars, t_datas *data, t_list_sh *list)
{
	if (data->input_str[vars->pars_i] && ft_is_redirection(data, vars->pars_i))
	{
		ft_is_left_redirec(vars, data);
		ft_is_right_redirec(vars, data);
		vars->type = REDIR;
		list = ft_write_list(data->input_str, list, vars);
		vars->type = 0;
	}
	return (list);
}
