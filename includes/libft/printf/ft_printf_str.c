/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:29:24 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:47:44 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_str(char *str, int *ptr)
{
	if (!str)
	{
		ft_printf_str("(null)", ptr);
		return ;
	}
	while (*str)
		ft_printf_char(*str++, ptr);
}
