/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:20:31 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:56:34 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_hexa(unsigned int nb, char c, int *ptr)
{
	size_t	n;

	if (nb == 0)
	{
		ft_printf_char('0', ptr);
		return ;
	}
	else
		n = nb;
	if (c == 'x')
		ft_printf_nbr(n, "0123456789abcdef", ptr);
	else
		ft_printf_nbr(n, "0123456789ABCDEF", ptr);
}
