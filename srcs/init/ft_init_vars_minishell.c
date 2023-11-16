/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars_minishell.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:46 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:33 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	*ft_calloc_sh(size_t nmemb, size_t size)
{
	char	*tab;
	int		i;
	int		len;

	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647)
		return (0);
	len = (nmemb * size) + 1;
	i = 0;
	tab = malloc(len);
	if (!tab)
		return (0);
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void	ft_malloc_fd_pipe(t_datas *data)
{
	int	i;

	i = 0;
	data->pid = 0;
	data->fd_pipe = 0;
	data->pid = ft_calloc_sh(sizeof(int), (data->nb_pipe + 2));
	if (!data->pid)
		return ;
	data->fd_pipe = ft_calloc_sh(sizeof(int *), (data->nb_pipe + 1));
	if (!data->fd_pipe)
		return ;
	while (i < data->nb_pipe + 1)
	{
		data->fd_pipe[i] = ft_calloc_sh(sizeof(int), 2);
		if (!data->fd_pipe[i])
			return ;
		i++;
	}
}

void	ft_init_vars_ms(t_datas *data)
{
	data->index_pid = 0;
	data->pid = 0;
	data->fd_pipe = 0;
	data->env = NULL;
	data->nb_pipe = 0;
	data->comp_input_str = 0;
	data->cmd_infile = NULL;
	data->cmd_outfile = NULL;
	data->fd_pipe = NULL;
	data->pid = NULL;
	data->path_env = NULL;
}
