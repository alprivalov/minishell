/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:17:42 by argomez           #+#    #+#             */
/*   Updated: 2022/11/18 15:42:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	display_char(t_printf_fd *datas, char c)
{
	datas->return_value += write(datas->file_descriptor, &c, 1);
}

void	display_string(t_printf_fd *datas, char *string)
{
	int	size;

	size = write(datas->file_descriptor, string, ft_strlen(string));
	datas->return_value = size;
}
