/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:48:54 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 15:15:22 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_ret_value;

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		g_ret_value = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	data_init_to_null(t_datas *data)
{
	data->home_directory = NULL;
	data->current_cmd_redir = NULL;
	data->cmd_infile = NULL;
	data->cmd_outfile = NULL;
	data->index_pid = 0;
	data->nb_pipe = 0;
	data->index_current_cmd = 0;
	data->input_str = NULL;
	data->pid = NULL;
	data->comp_input_str = 0;
	data->fd_pipe = NULL;
	data->path_env = NULL;
	data->env = NULL;
	data->cmds = NULL;
	data->list = NULL;
	ft_init_heredocs(data);
}

int	init_input_str(t_datas	*data, char **env)
{
	char	*prompt;
	char	*blink;

	prompt = NULL;
	blink = "\e[1;5;36m > \e[0;37m";
	data_init_to_null(data);
	if (data->pwd[0])
		prompt = multi_join(3, NULL, "\e[1;35m", data->pwd, blink);
	data->home_directory = find_in_env("HOME", env);
	data->input_str = readline(prompt);
	if (prompt)
		free(prompt);
	if (data->input_str && data->input_str[0])
		add_history(data->input_str);
	if (!data->input_str)
	{
		ft_free_env_list(data->env_sh);
		ft_free(data, 0);
		return (1);
	}
	return (0);
}

void	check_av(int ac, char **av)
{
	if (ac > 2)
	{
		printf("minishell: %s: No such file or directory", av[2]);
		exit(127);
	}
}

int	main(int ac, char **av, char **env)
{
	t_datas	data;

	g_ret_value = 0;
	data_init_to_null(&data);
	check_av(ac, av);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	ft_init_list_env(&data.env_sh, env, &data);
	while (1)
	{
		if (init_input_str(&data, env))
			return (1);
		if (ft_list_type(data.env_sh, &data, &data.list))
			continue ;
		data.cmds = malloc(sizeof(t_cmds) * (data.nb_pipe + 1));
		if (!data.cmds)
			return (0);
		data.cmds = ft_init_cmd(data.cmds, &data, data.list);
		if (data.redirections.run)
			ft_exec_cmd(&data, data.list, data.env_sh);
		if (ft_free(&data, 0))
			return (g_ret_value);
	}
	return (g_ret_value);
}
