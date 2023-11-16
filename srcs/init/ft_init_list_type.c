/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:45 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:01:30 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_list_type(t_list_env *env, t_datas *data, t_list_sh **new_list)
{
	t_list_sh	*list;

	ft_init_vars_ms(data);
	ft_init_path_env(data, env);
	ft_init_heredocs(data);
	(*new_list) = NULL;
	list = NULL;
	list = ft_pars_str(env, data, list);
	if (!list)
	{
		ft_free(data, 0);
		return (1);
	}
	(*new_list) = ft_join_list(list, (*new_list));
	ft_parsing_type(data, (*new_list));
	if (data->nb_pipe)
		ft_malloc_fd_pipe(data);
	ft_free_list(list);
	if (!new_list)
	{
		ft_free(data, 0);
		return (1);
	}
	return (0);
}
