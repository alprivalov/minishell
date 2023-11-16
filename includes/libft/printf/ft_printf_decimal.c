/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:42:00 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:49:00 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_decimal(int nb, int *ptr)
{
	size_t	n;

	if (nb == 0)
	{
		ft_printf_char('0', ptr);
		return ;
	}
	if (nb < 0)
	{
		ft_printf_char('-', ptr);
		n = nb;
		n *= -1;
	}
	else
		n = nb;
	ft_printf_nbr(n, "0123456789", ptr);
}
