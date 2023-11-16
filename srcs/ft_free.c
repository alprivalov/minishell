/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:05 by argomez           #+#    #+#             */
/*   Updated: 2022/12/26 18:32:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env(t_datas *data)
{
	int	i;

	if (!data->env)
		return ;
	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
	data->env = NULL;
}

void	ft_free_list(t_list_sh *list)
{
	t_list_sh	*tmp;

	if (list)
	{
		while (list)
		{
			tmp = list;
			if (tmp->content)
				free(tmp->content);
			list = list->next;
			free(tmp);
		}
	}
}

void	ft_free_env_list(t_list_env *list)
{
	t_list_env	*tmp;

	tmp = list;
	if (list)
	{
		while (list)
		{
			if (tmp->vars)
				free(tmp->vars);
			if (tmp->vars_value)
				free(tmp->vars_value);
			if (tmp->vars_all)
				free(tmp->vars_all);
			list = list->next;
			free(tmp);
			tmp = list;
		}
	}
}

static void	free_cmd_engine(int option, t_datas *data)
{
	int	i;

	i = 0;
	if (option == 2)
	{
		while (i < data->index_current_cmd + 1)
		{
			free_cmd(&data->cmds[i]);
			i++;
		}
	}
	else
	{
		while (i < data->nb_pipe + 1)
		{
			free_cmd(&data->cmds[i]);
			i++;
		}
	}
}

int	ft_free(t_datas *data, int option)
{
	if (data->redirections.heredocs[0] && (option == 2 || option == 0))
		delete_heredocs(data, option);
	ft_free_list(data->list);
	free_fd_pipe(data);
	free_path_env(data);
	free_env(data);
	if (data->pid)
		free(data->pid);
	if (data->input_str)
		free(data->input_str);
	free_cmd_engine(option, data);
	free(data->cmds);
	free(data->home_directory);
	if (data->comp_input_str == -1)
	{
		ft_free_env_list(data->env_sh);
		return (1);
	}
	return (0);
}
