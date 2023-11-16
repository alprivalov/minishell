/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:02 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:42 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list_sh	*ft_write_list(char *str_in, t_list_sh *list, t_pars *vars)
{
	char	*str;

	if (vars->type == DOUBLE_QUOTE)
		str = ft_substr_shell(str_in, vars->pars_start,
				vars->pars_i - vars->pars_start + 1);
	else if (vars->type == WHITE_SPACE)
		str = ft_strdup(" ");
	else if (vars->type == PIPE)
		str = ft_strdup("|");
	else if (vars->type == REDIR || vars->type == DOLLARS)
		str = ft_substr_shell(str_in, vars->pars_start,
				(vars->pars_i + 1) - vars->pars_start);
	else
		str = ft_substr_shell(str_in, vars->pars_start,
				vars->pars_i - vars->pars_start);
	if (!list)
		list = ft_d_lst(str, vars);
	else
		ft_d_lstadd_back(list, ft_d_lst(str, vars));
	free(str);
	return (list);
}

t_list_sh	*ft_pars_str(t_list_env	*env_sh, t_datas *data, t_list_sh *list)
{
	t_pars	vars;

	ft_init_vars(&vars);
	while (ft_is_space(data->input_str[vars.pars_i]))
		vars.pars_i++;
	while (data->input_str[vars.pars_i])
	{
		list = ft_pars_string(&vars, data, list);
		list = ft_pars_dquotes(&vars, data, list);
		list = ft_parsing_space(&vars, data, list);
		list = ft_pars_squotes(&vars, data, list);
		list = ft_pars_pipe(&vars, data, list);
		list = ft_pars_redirection(&vars, data, list);
		list = ft_parsing_dollars(list, &vars, data);
		if (data->input_str[vars.pars_i])
			vars.pars_i++;
	}
	list = ft_parsing_dollars_quotes(env_sh, list);
	if (vars.error)
	{
		ft_free_list(list);
		return (NULL);
	}
	return (list);
}
