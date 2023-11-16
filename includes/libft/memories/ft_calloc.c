/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:10:40 by argomez           #+#    #+#             */
/*   Updated: 2022/06/30 15:21:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*bloc;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	bloc = malloc(nmemb * size);
	if (bloc == NULL)
		return (NULL);
	ft_bzero(bloc, nmemb * size);
	return (bloc);
}
