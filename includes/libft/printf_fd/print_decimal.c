/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:15:14 by argomez           #+#    #+#             */
/*   Updated: 2022/11/18 15:42:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_decimal(t_printf_fd *datas)
{
	long int	number;

	number = va_arg(datas->parameters, int);
	if (number == 0)
		display_char(datas, '0');
	else if (number < 0)
	{
		display_char(datas, '-');
		number *= -1;
		print_number(datas, number, DECIMAL);
	}
	else
		print_number(datas, number, DECIMAL);
}
