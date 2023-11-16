/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:06:37 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*join(char *string1, char *string2)
{
	char	*final;
	int		lenght_1;
	int		lenght_2;

	lenght_1 = ft_strlen(string1);
	lenght_2 = ft_strlen(string2);
	final = malloc(sizeof(char) * (lenght_1 + lenght_2 + 1));
	if (!final)
		return (final);
	final[lenght_1 + lenght_2] = 0;
	lenght_1 = 0;
	while (string1 && string1[lenght_1] != 0)
	{
		final[lenght_1] = string1[lenght_1];
		lenght_1++;
	}
	free(string1);
	lenght_2 = 0;
	while (string2 && string2[lenght_2] != 0)
	{
		final[lenght_1] = string2[lenght_2];
		lenght_1++;
		lenght_2++;
	}
	return (final);
}

static int	check_to_free(char	*to_free)
{
	int	index;

	index = 0;
	while (to_free[index])
	{
		if (to_free[index] == '-' && to_free[index + 1] == '-')
			return (-1);
		else if (to_free[index] == '-' && to_free[index + 1] == '\0')
			return (-1);
		else if (to_free[index] == '-')
			index++;
		else if ('0' <= to_free[index] && to_free[index] <= '9')
			index++;
		else
			return (-1);
	}
	return (index);
}

static void	manage_free(char *to_free, char **strings)
{
	int	index;
	int	nb;

	index = 0;
	while (to_free[index])
	{
		while (to_free[index] == '-')
			index++;
		nb = ft_atoi(to_free + index);
		free(strings[nb - 1]);
		while ('0' <= to_free[index] && to_free[index] <= '9')
			index++;
	}
	free(strings);
}

char	*multi_join(int nb, char *to_free, ...)
{
	va_list	list;
	char	**strings;
	char	*final;
	int		index;

	final = NULL;
	va_start(list, to_free);
	strings = malloc(sizeof(char *) * (nb + 1));
	strings[nb] = NULL;
	index = 0;
	while (0 < nb)
	{
		strings[index] = va_arg(list, char *);
		final = join(final, strings[index]);
		index++;
		nb--;
	}
	va_end(list);
	if (!to_free || check_to_free(to_free) == 0)
	{
		free(strings);
		return (final);
	}
	manage_free(to_free, strings);
	return (final);
}
