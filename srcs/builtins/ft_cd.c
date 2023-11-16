/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:29 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:12:41 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cd_errors(t_cmds *cmd, int error)
{
	g_ret_value = 1;
	if (error == 1)
		ft_printf_fd(2, "bash: %s: too many arguments\n", cmd->args[0]);
	else if (error == 2)
		ft_printf_fd(2, "bash: %s: HOME not set\n", cmd->args[0]);
	else if (error == 3)
		ft_printf_fd(2, "bash: cd: %s: No such file or directory\n",
			cmd->args[1]);
}

static void	change_old_pwd_env(t_datas *data, char *old_pwd)
{
	t_list_env	*tmp;

	tmp = data->env_sh;
	while (tmp)
	{
		if (ft_strcmp("OLDPWD", tmp->vars) == -1)
		{
			if (tmp->vars_value)
				free(tmp->vars_value);
			tmp->vars_value = NULL;
			if (old_pwd)
				tmp->vars_value = ft_strdup(old_pwd);
			free(tmp->vars_all);
			tmp->vars_all = multi_join(3, "", tmp->vars, "=", tmp->vars_value);
		}
		tmp = tmp->next;
	}
}

static void	change_pwd_env(t_datas *data)
{
	t_list_env	*tmp;
	char		*old_pwd;

	old_pwd = NULL;
	tmp = data->env_sh;
	while (tmp)
	{
		if (ft_strcmp("PWD", tmp->vars) == -1)
		{
			if (tmp->vars_value)
			{
				old_pwd = ft_strdup(tmp->vars_value);
				free(tmp->vars_value);
			}
			tmp->vars_value = ft_strdup(data->pwd);
			free(tmp->vars_all);
			tmp->vars_all = multi_join(3, "", tmp->vars, "=", tmp->vars_value);
		}
		tmp = tmp->next;
	}
	change_old_pwd_env(data, old_pwd);
	free(old_pwd);
}

static int	change_to_home(t_cmds *cmd, t_datas *data)
{
	if (!data->home_directory || !is_in_env("HOME", data->env))
	{
		cd_errors(cmd, 2);
		return (0);
	}
	chdir(data->home_directory);
	getcwd(data->pwd, sizeof(data->pwd));
	change_pwd_env(data);
	return (1);
}

void	ft_cd(t_cmds *cmd, t_datas *data)
{
	g_ret_value = 0;
	if (cmd->args[0] && cmd->args[1] && cmd->args[2])
		cd_errors(cmd, 1);
	else if (cmd->args[1] && ft_strcmp(cmd->args[1], ".") == -1)
		return ;
	else if (cmd->args[1] && ft_strcmp(cmd->args[1], "..") == -1)
	{
		chdir("..");
		getcwd(data->pwd, sizeof(data->pwd));
	}
	else if (!cmd->args[1])
	{
		if (change_to_home(cmd, data))
			return ;
	}
	else if (cmd->args[1] && !chdir(cmd->args[1]))
		getcwd(data->pwd, sizeof(data->pwd));
	else if (cmd->args[1])
		cd_errors(cmd, 3);
	if (!g_ret_value)
		change_pwd_env(data);
}
