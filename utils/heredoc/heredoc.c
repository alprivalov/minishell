/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:38:03 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 18:04:04 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_globale(int key)
{
	(void)key;
	close(STDIN_FILENO);
	g_ret_value = 130;
}

void	no_limiter(char *prompt, char *str, int fd)
{
	char	*buffer;

	while (1)
	{
		buffer = readline(prompt);
		if (buffer == NULL)
		{
			free(buffer);
			ft_printf_fd(fd, "%s", str);
			free(str);
			return ;
		}
		str = ft_strjoin_frees(str, buffer, 'F');
		str = ft_strjoin_frees(str, "\n", 'F');
		free(buffer);
	}
}

void	with_limiter(char *prompt, char *str, int fd, char *lim)
{
	int		compare;
	char	*buffer;

	while (1)
	{
		buffer = readline(prompt);
		if (buffer == NULL)
		{
			free(buffer);
			if (g_ret_value != 130)
				printf("Bash : warning : here-document (wanted '%s')\n", lim);
			free(str);
			return ;
		}
		compare = ft_strcmp(lim, buffer);
		if (compare == -1)
		{
			free(buffer);
			ft_printf_fd(fd, "%s", str);
			free(str);
			return ;
		}
		str = multi_join(3, "1-2", str, buffer, "\n");
	}
}

static void	heredoc_child(int fd, char *prompt, char *limiter, t_datas *datas)
{
	if (limiter == NULL)
		no_limiter(prompt, NULL, fd);
	else
		with_limiter(prompt, NULL, fd, limiter);
	close(fd);
	if (g_ret_value == 130)
		close(STDOUT_FILENO);
	ft_free_env_list(datas->env_sh);
	ft_free(datas, 2);
	exit (g_ret_value);
}

char	*heredoc(char *prompt, char *limiter, t_datas *datas)
{
	char	*file_descriptor;
	int		fd;
	int		pid;

	file_descriptor = create_heredocs(datas);
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, change_globale);
		fd = open(file_descriptor, O_WRONLY | O_APPEND | O_CREAT, 0777);
		free(file_descriptor);
		heredoc_child(fd, prompt, limiter, datas);
	}
	signal(SIGINT, spec);
	waitpid(pid, &g_ret_value, WUNTRACED);
	if (WIFEXITED(g_ret_value))
		g_ret_value = WEXITSTATUS(g_ret_value);
	if (g_ret_value == 130)
		datas->redirections.run = 0;
	if (g_ret_value == 130)
		printf("\n");
	signal(SIGINT, sig_handler);
	return (file_descriptor);
}
