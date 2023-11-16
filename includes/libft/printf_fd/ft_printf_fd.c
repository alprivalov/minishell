/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:29:23 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 15:09:47 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	manage_parameter(t_printf_fd *datas, char parameter)
{
	if (parameter == 's')
		print_string(datas);
	else if (parameter == 'd')
		print_decimal(datas);
	else if (parameter == 'x')
		print_hexadecimal(datas);
	else if (parameter == '%')
		display_char(datas, '%');
}

int	ft_printf_fd(int file_descriptor, const char *args, ...)
{
	t_printf_fd		datas;
	int				index;

	va_start(datas.parameters, args);
	datas.return_value = 0;
	datas.file_descriptor = file_descriptor;
	index = 0;
	if (datas.file_descriptor == 2)
		datas.return_value += write(2, "\e[0;33m", 7);
	while (args[index] != 0)
	{
		if (args[index] == '%')
		{
			index++;
			manage_parameter(&datas, args[index]);
		}
		else
			display_char(&datas, args[index]);
		index++;
	}
	va_end(datas.parameters);
	return (datas.return_value);
}
