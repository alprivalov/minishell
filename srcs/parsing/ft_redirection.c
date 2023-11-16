/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:01 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:42 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_move_index(int i, t_pars *vars, t_datas *data)
{
	i++;
	vars->pars_i++;
	while (ft_is_space(data->input_str[i]))
		i++;
	return (i);
}

void	ft_prinft_error(t_pars *vars, char c)
{
	if (c && !vars->error && (c == '>' || c == '<'))
		printf("bash: syntax error near unexpected token `%c'\n", c);
	else if ((c && !vars->error && c == '|'))
		printf("bash: syntax error near unexpected token `%c'\n", c);
	else if (!vars->error)
		printf("bash: syntax error near unexpected token `newline'\n");
	vars->error++;
	g_ret_value = 2;
}

static int	ft_check_redir(t_datas *data, int i)
{
	if (data->input_str[i] == '<' || data->input_str[i] == '>')
		return (1);
	return (0);
}

void	ft_is_left_redirec(t_pars *vars, t_datas *data)
{
	int	i;

	if (data->input_str[vars->pars_i] == '<')
	{
		vars->pars_start = vars->pars_i;
		i = vars->pars_i;
		i++;
		while (data->input_str[i] && ft_is_space(data->input_str[i]))
			i++;
		if (!data->input_str[i])
			ft_prinft_error(vars, data->input_str[i]);
		if (data->input_str[i] && ft_check_redir(data, i)
			&& (data->input_str[i - 1] == '<'))
		{
			i = ft_move_index(i, vars, data);
			if (data->input_str[i] && (data->input_str[i] != '<'
					&& data->input_str[i] != '>'))
				return ;
			else
				ft_prinft_error(vars, data->input_str[i]);
		}
		else if (data->input_str[i] && ft_check_redir(data, i))
			ft_prinft_error(vars, data->input_str[i]);
	}
}

void	ft_is_right_redirec(t_pars *vars, t_datas *data)
{
	int	i;

	if (data->input_str[vars->pars_i] == '>')
	{
		vars->pars_start = vars->pars_i;
		i = vars->pars_i;
		i++;
		while (data->input_str[i] && ft_is_space(data->input_str[i]))
			i++;
		if (!data->input_str[i])
			ft_prinft_error(vars, data->input_str[i]);
		if (data->input_str[i] && data->input_str[i] == '>'
			&& data->input_str[i - 1] == '>')
		{
			i = ft_move_index(i, vars, data);
			if (data->input_str[i] && (data->input_str[i] != '<'
					&& data->input_str[i] != '>'))
				return ;
			else
				ft_prinft_error(vars, data->input_str[i]);
		}
		else if (data->input_str[i] && (data->input_str[i] == '<'
				|| data->input_str[i] == '>'))
			ft_prinft_error(vars, data->input_str[i]);
	}
}
