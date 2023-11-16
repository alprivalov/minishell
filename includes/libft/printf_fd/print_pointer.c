/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:42:32 by argomez           #+#    #+#             */
/*   Updated: 2022/11/18 15:48:55 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_pointer(t_printf_fd *datas)
{
	unsigned long long	number;

	number = va_arg(datas->parameters, unsigned long long);
	if (number == 0)
	{
		display_string(datas, "(nil)");
		return ;
	}
	display_string(datas, "0x");
	print_number(datas, number, HEXADECIMAL);
}
