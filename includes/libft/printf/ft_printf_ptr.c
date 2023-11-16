/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:39:42 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:47:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_ptr(unsigned long long nb, int *ptr)
{
	if (nb == 0)
	{
		ft_printf_str("(nil)", ptr);
		return ;
	}
	ft_printf_str("0x", ptr);
	ft_printf_nbr(nb, "0123456789abcdef", ptr);
}
