/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:45:32 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:56:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_afterpercent(va_list params, char *str, int *ptr)
{
	if (*str == 'c')
		ft_printf_char(va_arg(params, int), ptr);
	else if (*str == 's')
		ft_printf_str(va_arg(params, char *), ptr);
	else if (*str == 'p')
		ft_printf_ptr(va_arg(params, unsigned long long), ptr);
	else if (*str == 'd' || *str == 'i')
		ft_printf_decimal(va_arg(params, int), ptr);
	else if (*str == 'u')
		ft_printf_unsigned(va_arg(params, unsigned int), ptr);
	else if (*str == 'x' || *str == 'X')
		ft_printf_hexa(va_arg(params, unsigned int), *str, ptr);
	else if (*str == '%')
		ft_printf_char('%', ptr);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	char	*str;
	int		i;
	int		*ptr;

	i = 0;
	ptr = &i;
	va_start(params, format);
	str = (char *)format;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (ft_afterpercent(params, str, ptr) == 0)
				return (0);
		}
		else
			ft_printf_char(*str, ptr);
		str++;
	}
	va_end(params);
	return (i);
}
