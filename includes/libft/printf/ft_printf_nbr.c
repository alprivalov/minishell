/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:47:23 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:48:13 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_nbr(unsigned long long nb, char *base, int *ptr)
{
	if (nb >= ft_strlen(base))
	{
		ft_printf_nbr(nb / ft_strlen(base), base, ptr);
		ft_printf_nbr(nb % ft_strlen(base), base, ptr);
	}
	else
		ft_printf_char(base[nb], ptr);
}
