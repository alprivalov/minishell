/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:17:04 by argomez           #+#    #+#             */
/*   Updated: 2022/11/18 15:49:07 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_string(t_printf_fd *datas)
{
	char	*string;

	string = va_arg(datas->parameters, char *);
	display_string(datas, string);
}
