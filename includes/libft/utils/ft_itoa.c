/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:58:35 by argomez           #+#    #+#             */
/*   Updated: 2022/11/30 19:35:26 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
		nbr[0] = '0';
}

char	*ft_itoa(int n)
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
	nbr = malloc(sizeof(char) * size + 1);
	nbr[size] = '\0';
	if (!nbr)
		return (NULL);
	ft_fill(nbr, nb, size, n);
	return (nbr);
}
