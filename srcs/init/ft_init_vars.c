/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:47 by argomez           #+#    #+#             */
/*   Updated: 2022/12/26 18:28:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_vars(t_pars	*vars)
{
	vars->type = 0;
	vars->pars_i = 0;
	vars->pars_start = 0;
	vars->error = 0;
}

void	ft_init_list_env(t_list_env **env_sh, char **env, t_datas *data)
{
	int	i;

	i = 0;
	(*env_sh) = NULL;
	getcwd(data->pwd, sizeof(data->pwd));
	(*env_sh) = ft_d_lstnew_env(env[i]);
	i++;
	while (env[i])
	{
		ft_d_lstadd_back_env(env_sh, ft_d_lstnew_env(env[i]));
		i++;
	}
}

void	ft_init_env(t_datas *data, t_list_env *env_sh)
{
	int			i;
	t_list_env	*tmp;

	tmp = env_sh;
	i = 0;
	if (!tmp)
		return ;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	data->env = malloc(sizeof(char *) * (i + 1));
	if (!data->env)
		return ;
	data->env[i] = NULL;
	i = 0;
	while (env_sh)
	{
		data->env[i] = NULL;
		data->env[i] = ft_strdup(env_sh->vars_all);
		env_sh = env_sh->next;
		i++;
	}
}

void	ft_init_path_env(t_datas *data, t_list_env *env_sh)
{
	ft_init_env(data, env_sh);
	while (env_sh)
	{
		if (ft_strcmp(env_sh->vars, "PATH") == -1)
			break ;
		env_sh = env_sh->next;
	}
	if (env_sh)
		data->path_env = ft_split_sh(env_sh->vars_value, ':');
	else
		data->path_env = NULL;
}
