/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:58 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 14:30:32 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_redir_right(t_cmds *cmd, t_list_sh **list, int *flag)
{
	int			fd;
	struct stat	sb;

	free(cmd->outfile);
	(*list) = (*list)->next;
	while ((*list)->type_vars == WHITE_SPACE)
		(*list) = (*list)->next;
	if (access((*list)->content, F_OK) == 0)
	{
		stat((*list)->content, &sb);
		if (sb.st_mode & S_IFDIR)
			*flag = 1;
		if (!(sb.st_mode & S_IRWXU))
			*flag = 1;
		cmd->type_outfile = (*list)->type_vars;
		return (ft_strdup_env((*list)->content));
	}
	fd = open((*list)->content, O_CREAT | O_RDWR | O_APPEND, 0644);
	close(fd);
	cmd->type_outfile = (*list)->type_vars;
	return (ft_strdup_env((*list)->content));
}

char	*ft_redir_left(t_cmds *cmd, t_list_sh **list, int *flag)
{
	struct stat	sb;

	free(cmd->infile);
	(*list) = (*list)->next;
	while ((*list)->type_vars == WHITE_SPACE)
		(*list) = (*list)->next;
	if (access((*list)->content, F_OK) == 0)
	{
		stat((*list)->content, &sb);
		if (sb.st_mode & S_IFDIR)
			*flag = 1;
		if (!(sb.st_mode & S_IRWXU))
			*flag = 1;
		return (ft_strdup_env((*list)->content));
	}
	ft_printf_fd(2, "minishell: %s: No such file or directory\n",
		(*list)->content);
	*flag = 1;
	return (ft_strdup_env((*list)->content));
}

void	ft_parsing_redirection(t_cmds *cmd, t_list_sh *list, t_datas *data)
{
	int	flag;

	flag = 0;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	if (data->current_cmd_redir)
		list = data->current_cmd_redir;
	while (list && list->type_vars != PIPE)
	{
		if (list->next && list->type_vars == S_REDIR_L && flag == 0)
			cmd->infile = ft_redir_left(cmd, &list, &flag);
		else if (list->next && (list->type_vars == S_REDIR_R
				|| list->type_vars == D_REDIR_R) && flag == 0)
			cmd->outfile = ft_redir_right(cmd, &list, &flag);
		else if (list->type_vars == D_REDIR_L
			&& ft_strcmp(list->content, "<<" ) >= 0 && data->redirections.run)
			cmd->infile = heredoc("> ", list->content, data);
		list = list->next;
	}
	if (list && list->next)
		data->current_cmd_redir = list->next;
	else
		data->current_cmd_redir = NULL;
}
