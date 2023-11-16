/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:15:57 by argomez           #+#    #+#             */
/*   Updated: 2022/11/18 15:42:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_hexadecimal(t_printf_fd *datas)
{
	long int	number;

	number = va_arg(datas->parameters, int);
	if (number == 0)
	{
		display_char(datas, '0');
		return ;
	}
	else if (number < 0)
	{
		number *= -1;
		print_number(datas, number, HEXADECIMAL);
	}
	else
		print_number(datas, number, HEXADECIMAL);
}
