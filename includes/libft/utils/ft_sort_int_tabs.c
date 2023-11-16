/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:41:22 by argomez           #+#    #+#             */
/*   Updated: 2022/12/21 19:47:44 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tabs(int *array, int size)
{
	int	index;

	if (!array || !size)
		return ;
	index = 0;
	while (index < size)
	{
		if (array[index] > array[index + 1])
		{
			array[index] += array[index + 1];
			array[index + 1] = array[index] - array[index + 1];
			array[index] -= array[index + 1];
			index = 0;
		}
		index++;
	}
}
