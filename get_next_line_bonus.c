/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:19:27 by bsen              #+#    #+#             */
/*   Updated: 2024/02/02 23:45:08 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*ft_copy(char *buffer, char *temp)
{
	char	*res;

	res = 0;
	if (!buffer && temp)
	{
		res = ft_strdup(temp);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin(buffer, temp);
	free_buffer(&buffer, 0);
	return (res);
}

static int	ft_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!buffer)
		return (free_buffer(&buffer, 0));
	while (buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (free_buffer(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

static char	*ft_buffer(char *buffer)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n')
		i++;
	if (buffer[i + 1] == '\0')
		return (free_buffer(&buffer, 0));
	res = ft_substr(buffer, i + 1, ft_strlen(buffer));
	if (!res)
		return (free_buffer(&buffer, 0));
	free_buffer(&buffer, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char		temp[BUFFER_SIZE + 1];
	long		ret;
	static char	*buffer[4096];
	char		*line;

	line = 0;
	ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (free_buffer(&buffer[fd], 0));
	while (ret > 0)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if ((ret <= 0 && !buffer[fd]) || ret == -1)
			return (free_buffer(&buffer[fd], 0));
		temp[ret] = 0;
		buffer[fd] = ft_copy(buffer[fd], temp);
		if (ft_nl(buffer[fd]))
		{
			line = ft_line(buffer[fd]);
			if (!line)
				return (free_buffer(&buffer[fd], 0));
			return (buffer[fd] = ft_buffer(buffer[fd]), line);
		}
	}
	return (free_buffer(&buffer[fd], 1));
}
