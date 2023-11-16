/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:33 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 15:07:56 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list_env	*ft_export_exist_unset(t_list_env *env_sh, char *str)
{
	if (!str)
		return (env_sh);
	while (env_sh)
	{
		if (env_sh && ft_strcmp(env_sh->vars, str) == -1)
			return (env_sh);
		env_sh = env_sh->next;
	}
	return (env_sh);
}

static void	free_unset(t_list_env *tmp)
{
	if (tmp->vars)
		free(tmp->vars);
	if (tmp->vars_value)
		free(tmp->vars_value);
	if (tmp->vars_all)
		free(tmp->vars_all);
}

static void	change_env(t_list_env *tmp, t_datas *data)
{
	if (tmp->preview && tmp->next)
		tmp->preview->next = tmp->next;
	if (tmp->preview && tmp->next)
		tmp->next->preview = tmp->preview;
	if (tmp->preview == NULL)
	{
		tmp->next->preview = 0;
		data->env_sh = data->env_sh->next;
	}
	if (tmp->next == 0)
		tmp->preview->next = 0;
}

static int	check_arg(char *str)
{
	int	i;

	i = 0;
	if ((str[i] < 'a' || str[i] > 'z')
		&& (str[i] < 'A' || str[i] > 'Z') && str[i] != '_')
		return (0);
	i++;
	while (str[i])
	{
		if ((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < 'A' || str[i] > 'Z')
			&& (str[i] < '0' || str[i] > '9') && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_unset(t_cmds *cmd, t_datas *data)
{
	t_list_env	*tmp;
	int			index;

	if (!cmd->args[1])
		return ;
	index = 0;
	while (cmd->args[++index])
	{
		if (!check_arg(cmd->args[index]))
		{
			ft_printf_fd(2, "bash: unset: `%s': not a valid identifier\n",
				cmd->args[index]);
			continue ;
		}
		tmp = ft_export_exist_unset(data->env_sh, cmd->args[index]);
		if (tmp)
		{
			free_unset(tmp);
			change_env(tmp, data);
			free(tmp);
		}
	}
}
