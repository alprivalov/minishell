/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:43 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:20:14 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_nb_ligne(t_list_sh *tmp)
{
	int	ligne;

	ligne = 0;
	while (tmp && tmp->type_vars != PIPE)
	{
		if (tmp->type_vars == CMD)
			ligne++;
		tmp = tmp->next;
	}
	return (ligne);
}

static void	free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}

static char	**transform_tab(char **tab, int size)
{
	char	**new;
	int		index;
	int		index_new;

	size = 0;
	index = 0;
	index_new = 0;
	while (tab[index] && tab[index][0] == '\0')
		index++;
	while (tab[index + size])
		size++;
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = NULL;
	while (tab[index + index_new])
	{
		new[index_new] = ft_strdup(tab[index + index_new]);
		index_new++;
	}
	free_tab(tab);
	return (new);
}

static char	**ft_init_cmd_args(t_list_sh *list)
{
	char		**tab;
	int			ligne;
	int			index;
	t_list_sh	*tmp;

	tmp = list;
	index = 0;
	ligne = count_nb_ligne(tmp);
	tab = malloc(sizeof(char *) * (ligne + 1));
	if (!tab)
		return (NULL);
	tab[ligne] = 0;
	while (list && list->type_vars != PIPE)
	{
		if (list->type_vars == CMD)
		{
			tab[index] = ft_strdup(list->content);
			index++;
		}
		list = list->next;
	}
	if (tab && index > 0 && !tab[0][0] && tab[1])
		tab = transform_tab(tab, ligne);
	return (tab);
}

t_cmds	*ft_init_cmd(t_cmds *cmds, t_datas *data, t_list_sh *list)
{
	int		index;
	t_cmds	*cmd;

	index = 0;
	while (index < data->nb_pipe + 1)
	{
		cmd = &cmds[index];
		cmd->cmd_number = index;
		cmd->args = ft_init_cmd_args(list);
		if (cmd->args)
			cmd->cmd = cmd->args[0];
		else
			cmd->cmd = NULL;
		ft_parsing_redirection(cmd, list, data);
		cmd->env = data->env;
		index++;
		list_next_cmd(&list);
		if (list && list->next)
			list = list->next;
		data->index_current_cmd++;
	}
	return (cmds);
}
