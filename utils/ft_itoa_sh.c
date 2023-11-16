/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_sh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:49:05 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	ft_findsize(size_t nb)
{
	size_t	size;

	size = 0;
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static void	ft_fill(char *nbr, size_t nb, size_t size, int n)
{
	if (n < 0)
	{
		nbr[0] = '-';
		while (nb > 0)
		{
			nbr[--size] = (nb % 10) + 48;
			nb /= 10;
		}
	}
	else if (n > 0)
	{
		while (nb > 0)
		{
			nbr[--size] = (nb % 10) + 48;
			nb /= 10;
		}
	}
	else
	{
		nbr[0] = '0';
		nbr[1] = '\0';
	}
}

char	*ft_itoa_sh(int n)
{
	char	*nbr;
	size_t	nb;
	size_t	size;

	size = 0;
	nb = 0;
	if (n < 0)
	{
		nb = n;
		nb = nb * -1;
		size++;
	}
	else if (n > 0)
		nb = n;
	else
		size++;
	size += ft_findsize(nb);
	nbr = ft_calloc(sizeof(char), size + 1);
	if (!nbr)
		return (NULL);
	ft_fill(nbr, nb, size, n);
	nbr[size] = 0;
	return (nbr);
}
