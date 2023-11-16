/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:46:56 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:56:22 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_parsing_export(char *str)
{
	int	i;

	i = 0;
	if ((str[i] < 'a' || str[i] > 'z')
		&& (str[i] < 'A' || str[i] > 'Z') && str[i] != '_')
		return (0);
	i++;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i - 1] && str[i - 1] == '+' && str[i] == '=')
		return (2);
	else if (str[i] && str[i] == '=')
		return (1);
	else
		return (3);
}

int	ft_export_exist(t_list_env **env_sh, char *vars_export)
{
	t_list_env	*tmp;

	tmp = (*env_sh);
	while (tmp)
	{
		if (tmp && ft_strcmp(tmp->vars, vars_export) == -1)
			if (tmp && ft_strcmp(tmp->vars, vars_export) == -1)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_pars_export(char	**str, char *arg)
{
	if (ft_parsing_export(arg) == 1
		|| ft_parsing_export(arg) == 3)
		(*str) = ft_init_export_no_plus(arg);
	else if (ft_parsing_export(arg) == 2)
		(*str) = ft_init_export_plus(arg);
	else if (ft_parsing_export(arg) == 0)
	{
		ft_printf_fd(2, "bash: export: `%s': not a valid identifier\n", arg);
		g_ret_value = 1;
		return (0);
	}
	if ((*str) == NULL)
	{
		ft_printf_fd(2, "bash: export: `%s': not a valid identifier\n", arg);
		g_ret_value = 1;
		return (0);
	}
	return (1);
}

static void	frees(char *str, char *vars_export, char *value_vars)
{
	free(str);
	free(vars_export);
	free(value_vars);
}

void	ft_export(t_cmds *cmd, t_list_env **env_sh)
{
	char	*str;
	char	*vars_export;
	char	*value_vars;
	int		index;

	if (!cmd || !cmd->args[1])
		ft_printf_list_export(cmd, env_sh);
	else
	{
		index = 0;
		while (cmd->args[++index])
		{
			if (!ft_pars_export(&str, cmd->args[index]))
				continue ;
			vars_export = ft_vars_exports(str);
			value_vars = ft_value_vars(str, vars_export);
			if (!ft_export_exist(env_sh, vars_export))
				ft_d_lstadd_back_env(env_sh, ft_d_lstnew_env(str));
			else if (ft_parsing_export(cmd->args[index]) == 1)
				ft_exp_ow_char(env_sh, value_vars, vars_export);
			else if (ft_parsing_export(cmd->args[index]) == 2)
				ft_add_char(env_sh, vars_export, value_vars);
			frees(str, vars_export, value_vars);
		}
	}
}
