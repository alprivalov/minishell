/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_env_vars_exist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:49 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:34 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_vars_pars_dollars(t_pars *vars)
{
	vars->i = 0;
	vars->pars_start = 0;
}

char	*check_env(t_list_env *env_sh, char *str)
{
	while (env_sh)
	{
		if (ft_strcmp(env_sh->vars, str) == -1)
		{
			free(str);
			return (ft_strdup(env_sh->vars_value));
		}
		env_sh = env_sh->next;
	}
	free(str);
	return (NULL);
}

char	*ft_if_env_vars_exist(t_list_env *env_sh, t_list_sh **tmp)
{
	t_pars	vars;

	vars.str_out = NULL;
	if (g_ret_value > 255)
		g_ret_value %= 256;
	ft_init_vars_pars_dollars(&vars);
	if ((*tmp)->content[0] == '\"')
		vars.pars_start++;
	while ((*tmp)->content[vars.i])
		ft_pars_env(env_sh, tmp, &vars);
	if ((*tmp)->content[vars.i - 1] == '\"')
		vars.str_out = ft_strjoin_frees(vars.str_out,
				ft_substr_shell((*tmp)->content, vars.pars_start,
					vars.i - vars.pars_start - 1), 'A');
	else
		vars.str_out = ft_strjoin_frees(vars.str_out,
				ft_substr_shell((*tmp)->content,
					vars.pars_start, vars.i - vars.pars_start), 'A');
	free((*tmp)->content);
	return (vars.str_out);
}
