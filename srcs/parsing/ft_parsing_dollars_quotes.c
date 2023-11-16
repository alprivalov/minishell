/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_dollars_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:56 by argomez           #+#    #+#             */
/*   Updated: 2022/12/28 14:12:30 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list_sh	*ft_parsing_dollars_quotes(t_list_env *env_sh, t_list_sh *list)
{
	t_list_sh	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp && tmp->type_vars == SINGLE_QUOTE)
		{
			tmp = tmp->next;
			continue ;
		}
		if (tmp->content[0] == '\"' && tmp->content[ft_strlen(tmp->content) - 1]
			== '\"')
			tmp->content = ft_if_env_vars_exist(env_sh, &tmp);
		else if (tmp->content[0] == '$')
			tmp->content = ft_if_env_vars_exist(env_sh, &tmp);
		tmp = tmp->next;
	}
	return (list);
}
