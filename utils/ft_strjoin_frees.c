/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_frees.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:29:11 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:17 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fill_first_part(char *string_1, char *final_string, char option)
{
	int	index;

	index = 0;
	while (string_1 && string_1[index])
	{
		final_string[index] = string_1[index];
		index++;
	}
	if (string_1 && (option == 'F' || option == 'A'))
		free(string_1);
	return (index);
}

void	fill_second_part(char *string_2, char *final, char option, int index)
{
	int	index_s;

	index_s = 0;
	while (string_2 && string_2[index_s])
	{
		final[index++] = string_2[index_s];
		index_s++;
	}
	if (string_2 && (option == 'S' || option == 'A'))
		free(string_2);
}

char	*ft_strjoin_frees(char *string_1, char *string_2, char option)
{
	char	*final_string;
	int		index;
	int		lenght;

	lenght = ft_strlen(string_1) + ft_strlen(string_2);
	final_string = malloc(sizeof(char) * (lenght + 1));
	if (!final_string)
		return (final_string);
	final_string[lenght] = '\0';
	index = fill_first_part(string_1, final_string, option);
	fill_second_part(string_2, final_string, option, index);
	return (final_string);
}
