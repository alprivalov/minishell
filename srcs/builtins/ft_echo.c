/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:30 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 19:08:58 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	arg_is_an_option(char *arg)
{
	int	index;

	if (!arg)
		return (0);
	if (!(arg[0] == '-' && arg[1] == 'n'))
		return (0);
	index = 2;
	while (arg[index])
	{
		if (arg[index] != 'n')
			return (0);
		index++;
	}
	return (1);
}

void	ft_echo(t_cmds *cmd)
{
	char	**args;
	int		line_return;
	int		index;
	int		fd_outfile;

	fd_outfile = 1;
	if (cmd->outfile)
		fd_outfile = open(cmd->outfile, O_WRONLY | O_APPEND);
	args = cmd->args;
	index = 1;
	while (args[index] && arg_is_an_option(args[index]))
		index++;
	line_return = index;
	while (cmd && args && args[index])
	{
		ft_printf_fd(fd_outfile, "%s", args[index]);
		if (cmd && args && args[index + 1])
			ft_printf_fd(fd_outfile, " ");
		index++;
	}
	if (line_return == 1)
		ft_printf_fd(fd_outfile, "\n");
	close(fd_outfile);
}
