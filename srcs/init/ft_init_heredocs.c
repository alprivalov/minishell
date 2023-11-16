/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:44 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 14:22:10 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_heredocs(t_datas *datas)
{
	t_redirections	*redirs;
	int				index;

	redirs = &datas->redirections;
	redirs->run = 1;
	redirs->index_heredoc = 0;
	redirs->index_name = 0;
	index = 0;
	while (index < 4096)
	{
		redirs->heredocs[index] = NULL;
		index++;
	}
	(void)redirs;
}
