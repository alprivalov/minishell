/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:01 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	type_redir_r_d(t_list_sh **tmp)
{
	(*tmp)->type_vars = D_REDIR_R;
	if ((*tmp)->next && !(size_t)ft_strncmp((*tmp)->next->content, " ",
			(size_t)ft_strlen((*tmp)->content)))
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = WHITE_SPACE;
		if ((*tmp)->next)
		{
			(*tmp) = (*tmp)->next;
			(*tmp)->type_vars = D_REDIR_R;
		}
	}
	else if ((*tmp)->next)
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = D_REDIR_R;
	}
}

void	type_redir_r(t_list_sh **tmp)
{
	(*tmp)->type_vars = S_REDIR_R;
	if ((*tmp)->next && !(size_t)ft_strncmp((*tmp)->next->content, " ",
			(size_t)ft_strlen((*tmp)->content)))
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = WHITE_SPACE;
		if ((*tmp)->next)
		{
			(*tmp) = (*tmp)->next;
			(*tmp)->type_vars = S_REDIR_R;
		}
	}
	else if ((*tmp)->next)
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->type_vars = S_REDIR_R;
	}
}

static int	if_quotes(int type_vars)
{
	if (type_vars != DOUBLE_QUOTE && type_vars != SINGLE_QUOTE)
		return (1);
	else
		return (0);
}

void	ft_check_type(t_datas *data, t_list_sh **tmp)
{
	if (ft_strcmp((*tmp)->content, ">") == -1
		&& if_quotes((*tmp)->type_vars))
		type_redir_r(tmp);
	else if (ft_strcmp((*tmp)->content, ">>") == -1
		&& if_quotes((*tmp)->type_vars))
		type_redir_r_d(tmp);
	else if (ft_strcmp((*tmp)->content, "<") == -1
		&& if_quotes((*tmp)->type_vars))
		type_redir_l(tmp);
	else if (ft_strcmp((*tmp)->content, "<<") == -1
		&& if_quotes((*tmp)->type_vars))
		type_redir_l_d(tmp);
	else if (ft_strcmp((*tmp)->content, " ") == -1)
		(*tmp)->type_vars = WHITE_SPACE;
	else if (ft_strcmp((*tmp)->content, "|") == -1
		&& (*tmp)->next && if_quotes((*tmp)->type_vars))
	{
		data->nb_pipe++;
		(*tmp)->type_vars = PIPE;
	}
	else
		(*tmp)->type_vars = CMD;
}

void	ft_parsing_type(t_datas *data, t_list_sh *new_list)
{
	t_list_sh	*tmp;

	tmp = new_list;
	while (tmp)
	{
		ft_check_type(data, &tmp);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}
