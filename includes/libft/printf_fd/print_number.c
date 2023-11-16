/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:16:35 by argomez           #+#    #+#             */
/*   Updated: 2022/11/18 15:42:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_number(t_printf_fd *datas, long long int number, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (number >= len)
	{
		print_number(datas, number / len, base);
		print_number(datas, number % len, base);
	}
	else
		display_char(datas, base[number]);
}
