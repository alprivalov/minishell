/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:07 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 15:07:15 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_strcmp_sort(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == 0 && s2[i] == 0)
		return (-1);
	return (s1[i] - s2[i]);
}

void	sort_list(t_list_env **new_list)
{
	char		*tmp_value;
	char		*tmp_vars;
	int			flag;

	while ((*new_list)->next)
	{
		flag = 0;
		if (ft_strcmp_sort((*new_list)->vars, (*new_list)->next->vars) > 0)
		{
			flag = 1;
			tmp_vars = (*new_list)->next->vars;
			tmp_value = (*new_list)->next->vars_value;
			(*new_list)->next->vars = (*new_list)->vars;
			(*new_list)->next->vars_value = (*new_list)->vars_value;
			(*new_list)->vars = tmp_vars;
			(*new_list)->vars_value = tmp_value;
			while ((*new_list)->preview)
				(*new_list) = (*new_list)->preview;
		}
		if (flag == 0)
			(*new_list) = (*new_list)->next;
	}
}

void	init_list_sort(t_list_env *env_sh, t_list_env **new_list)
{
	(*new_list) = NULL;
	(*new_list) = ft_d_lstnew_env(env_sh->vars_all);
	env_sh = env_sh->next;
	while (env_sh)
	{
		ft_d_lstadd_back_env(new_list, ft_d_lstnew_env(env_sh->vars_all));
		env_sh = env_sh->next;
	}
	sort_list(new_list);
	while ((*new_list)->preview)
				(*new_list) = (*new_list)->preview;
}

void	ft_printf_list_export(t_cmds *cmd, t_list_env **env_sh)
{
	int			fd;
	t_list_env	*new;
	t_list_env	*tmp_free;

	new = NULL;
	init_list_sort((*env_sh), &new);
	fd = 1;
	if (cmd->outfile)
		fd = open(cmd->outfile, O_WRONLY | O_APPEND);
	tmp_free = new;
	while (new)
	{
		if (new->vars_value && new->vars_value[0]
			&& !(ft_strcmp(new->vars, "_") == -1))
			ft_printf_fd(fd, "declare -x %s=\"%s\"\n", new->vars,
				new->vars_value);
		else if (new->vars && !(ft_strcmp(new->vars, "_") == -1))
			ft_printf_fd(fd, "declare -x %s\n", new->vars);
		new = new->next;
	}
	ft_free_env_list(tmp_free);
	if (fd != 1)
		close(fd);
}

void	ft_printf_list_env(t_cmds *cmd, t_list_env **env_sh)
{
	t_list_env	*tmp;
	int			fd_outfile;

	fd_outfile = 1;
	if (cmd->outfile)
		fd_outfile = open(cmd->outfile, O_WRONLY | O_APPEND);
	if ((*env_sh))
	{
		tmp = (*env_sh);
		while (tmp)
		{
			if (tmp->vars_value && ft_strchrc(tmp->vars_all, '='))
				ft_printf_fd(fd_outfile, "%s=%s\n", tmp->vars, tmp->vars_value);
			tmp = tmp->next;
		}
	}
	if (fd_outfile != 1)
		close(fd_outfile);
}
