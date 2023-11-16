/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:31 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:48:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "limits.h"

int	ft_check_len(char *str)
{
	char	*max_int;
	int		status;

	if (str[0] == '-')
		status = 1;
	else
		status = 0;
	if ((int)ft_strlen(str) > 19 + status)
		return (1);
	if ((int)ft_strlen(str) < 19 + status)
		return (0);
	if (status == 1)
		max_int = ft_strdup_env("9223372036854775808");
	else
		max_int = ft_strdup_env("9223372036854775807");
	if (ft_strncmp(str + status, max_int, 19 + status) <= 0)
	{
		free(max_int);
		return (0);
	}
	free(max_int);
	return (1);
}

static void	check_str(t_cmds *cmd, t_datas *data)
{
	int	i;

	i = 0;
	if (cmd->args[1][i] == '-' || cmd->args[1][i] == '+')
		i++;
	while (cmd->args[1][i])
	{
		if (cmd->args[1][i] && (cmd->args[1][i] < '0'
			|| cmd->args[1][i] > '9'))
		{
			ft_printf_fd(2, "bash: exit: %s: numeric argument required\n",
				cmd->args[1]);
			ft_free(data, 0);
			exit(2);
		}
		i++;
	}
}

void	ft_exit_num_arg(t_cmds *cmd, t_datas *data)
{
	long long int	return_value;

	check_str(cmd, data);
	if (ft_check_len(cmd->args[1]))
	{
		ft_printf_fd(2, "bash: exit: %s: numeric argument required\n",
			cmd->args[1]);
		ft_free(data, 0);
		exit(2);
	}
	return_value = ft_atoi(cmd->args[1]);
	if (return_value > 255)
		return_value %= 256;
	g_ret_value = return_value;
}

void	ft_exit(t_cmds *cmd, t_datas *data)
{
	printf("exit\n");
	data->comp_input_str = -1;
	if (cmd->args[1])
		ft_exit_num_arg(cmd, data);
	if (cmd->args[0] && cmd->args[1] && cmd->args[2])
	{
		data->comp_input_str = 0;
		ft_printf_fd(2, "bash: exit: too many arguments\n");
		g_ret_value = 1;
		return ;
	}
}
