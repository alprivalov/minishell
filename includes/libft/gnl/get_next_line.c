/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:19:42 by argomez           #+#    #+#             */
/*   Updated: 2022/05/20 10:49:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*get_save(char *line)
{
	char	*new_save;
	size_t	size;

	if (line[0] == '\0' || ft_strchr(line, '\n') == 0)
		return (NULL);
	while (*line != '\n')
		line++;
	line++;
	size = 0;
	while (line[size] != '\0')
		size++;
	new_save = NULL;
	new_save = ft_calloc(size + 1, sizeof(char));
	size = 0;
	while (line[size] != '\0')
	{
		new_save[size] = line[size];
		size++;
	}
	new_save[size] = '\0';
	return (new_save);
}

static char	*get_line_cut(char *line)
{
	char	*new_line;
	size_t	size;
	size_t	siz;

	size = 0;
	if (!line)
		return (NULL);
	while (line[size] && line[size] != '\n')
		size++;
	if (line[size] == '\n')
		size++;
	new_line = ft_calloc(size + 1, sizeof(char));
	new_line[size] = '\0';
	siz = 0;
	while (line[siz] && line[siz] != '\n')
	{
		new_line[siz] = line[siz];
		siz++;
	}
	new_line[siz] = line[siz];
	free(line);
	return (new_line);
}

static char	*get_read_fd(int fd)
{
	char	*buffer;
	char	*result;
	int		readed;

	result = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (ft_strchr(result, '\n') == 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
		{
			if (ft_strchr(result, '\n') == 0 && result[0] != '\0')
				return (free(buffer), result);
			return (free(buffer), free(result), NULL);
		}
		result = ft_strjoin_malloc(result, buffer);
	}
	return (free(buffer), result);
}

char	*get_next_line(int fd)
{
	static char	*save_lines[4096];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save_lines[fd])
		save_lines[fd] = ft_calloc(sizeof(char), 1);
	line = get_read_fd(fd);
	if (!line)
		line = ft_calloc(sizeof(char), 1);
	tmp = ft_strjoin_malloc(save_lines[fd], line);
	free(line);
	line = tmp;
	save_lines[fd] = get_save(line);
	line = get_line_cut(line);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}
