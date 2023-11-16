/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:57 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:39 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_alpha_num_underscore(char c)
{
	if (c == '_' || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_get_env(char *str_in)
{
	int		i;
	char	*str_out;

	i = 1;
	if (!str_in)
		return (NULL);
	while (str_in[i] && ft_is_alpha_num_underscore(str_in[i]))
		i++;
	str_out = ft_substr_shell(str_in, 1, i - 1);
	return (str_out);
}

static void	ft_return_value(t_list_sh **tmp, t_pars *vars)
{
	vars->str_out = multi_join(3, "1-2-3", vars->str_out,
			ft_substr_shell((*tmp)->content, vars->pars_start,
				vars->i - vars->pars_start), ft_itoa(g_ret_value));
	vars->pars_start = vars->i + 2;
}

static void	ft_env_value(t_list_env *env_sh, t_list_sh **tmp, t_pars *vars)
{
	char	*env;
	int		len_env;

	env = ft_get_env((*tmp)->content + vars->i);
	len_env = ft_strlen(env);
	vars->str_out = multi_join(3, "1-2-3", vars->str_out,
			ft_substr_shell((*tmp)->content, vars->pars_start,
				vars->i - vars->pars_start), check_env(env_sh, env));
	vars->pars_start = (vars->i + len_env + 1);
}

void	ft_pars_env(t_list_env *env_sh, t_list_sh **tmp, t_pars	*vars)
{
	if ((*tmp)->content[vars->i] == '$' && (*tmp)->content[vars->i + 1]
		&& (*tmp)->content[vars->i + 1] == '?')
		ft_return_value(tmp, vars);
	else if ((*tmp)->content[vars->i] == '$' && (*tmp)->content[vars->i + 1]
		&& (*tmp)->content[vars->i + 1] == ' ')
		vars->i++;
	else if ((*tmp)->content[vars->i] == '$' && (*tmp)->content[vars->i + 1]
		&& (*tmp)->content[vars->i + 1] != '\"')
		ft_env_value(env_sh, tmp, vars);
	vars->i++;
}
