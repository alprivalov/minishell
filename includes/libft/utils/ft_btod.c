/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:27:56 by argomez           #+#    #+#             */
/*   Updated: 2022/08/11 21:16:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_btod(int *numbers)
{
	long long	result;
	int			index;

	result = 0;
	index = 0;
	while (index < 8)
	{
		result *= 2;
		result += numbers[index++];
	}
	return (result);
}
