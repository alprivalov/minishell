/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:17:54 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 10:58:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	result;
	size_t	nb;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = n;
		nb *= -1;
	}
	else
		nb = n;
	if (nb > 0)
	{
		result = (nb % 10) + 48;
		nb /= 10;
		if (nb > 0)
			ft_putnbr_fd(nb, fd);
		write(fd, &result, 1);
	}
}
