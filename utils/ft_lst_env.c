/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:49:06 by argomez           #+#    #+#             */
/*   Updated: 2022/12/23 18:49:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strcpy_env(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != '=')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_env(const char *s)
{
	char	*tab;
	char	*str;

	str = (char *)s;
	tab = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tab)
		return (0);
	tab = ft_strcpy_env(tab, str);
	return (tab);
}

t_list_env	*ft_d_lstnew_env(char *str)
{
	t_list_env	*new;

	new = malloc(sizeof(t_list_env) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->preview = NULL;
	new->vars = ft_strdup_env(str);
	new->len = ft_strlen(new->vars);
	new->vars_all = ft_strdup(str);
	if (str[new->len])
		new->vars_value = ft_substr_env(str, new->len + 1,
				ft_strlen(str) - new->len);
	else
		new->vars_value = NULL;
	return (new);
}

t_list_env	*ft_d_lstlast_env(t_list_env *env_sh)
{
	if (env_sh)
	{
		while (env_sh -> next)
			env_sh = env_sh -> next;
	}
	return (env_sh);
}

void	ft_d_lstadd_back_env(t_list_env **env_sh, t_list_env *new)
{
	t_list_env	*temp;

	if (env_sh)
	{
		temp = ft_d_lstlast_env((*env_sh));
		temp -> next = new;
		new -> preview = temp;
	}
}
