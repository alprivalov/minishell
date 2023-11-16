/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:36:29 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*create_heredocs(t_datas *datas)
{
	t_redirections	*redirs;
	char			*file;

	free(datas->cmds[datas->index_current_cmd].infile);
	datas->cmds[datas->index_current_cmd].infile = NULL;
	redirs = &datas->redirections;
	while (redirs->index_name < 500000)
	{
		file = multi_join(2, "2", ".heredoc_", ft_itoa_sh(redirs->index_name));
		if (access(file, F_OK))
		{
			redirs->heredocs[redirs->index_heredoc] = file;
			redirs->index_heredoc++;
			redirs->index_name++;
			return (ft_strdup(file));
		}
		redirs->index_name++;
		free(file);
	}
	return ("CREATE_ERROR");
}

char	*delete_heredocs(t_datas *datas, int option)
{
	t_redirections	*redirs;
	int				index;

	index = 0;
	redirs = &datas->redirections;
	if (!option)
	{
		while (redirs->heredocs[index])
		{
			unlink(redirs->heredocs[index]);
			free(redirs->heredocs[index]);
			redirs->heredocs[index] = NULL;
			index++;
		}
	}
	else if (option == 2)
	{
		while (redirs->heredocs[index])
		{
			free(redirs->heredocs[index]);
			redirs->heredocs[index] = NULL;
			index++;
		}
	}
	return ("DELETE_OK");
}
