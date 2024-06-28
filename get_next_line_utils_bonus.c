/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:19:49 by bsen              #+#    #+#             */
/*   Updated: 2024/02/02 23:43:52 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > s_len)
		len = s_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < s_len && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*p;
	int		i;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	p = malloc((sizeof(char)) * len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i])
	{
		p[len++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		p[len++] = s2[i++];
	}
	p[len] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = (char)s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*free_buffer(char **buffer, int i)
{
	char	*line;

	if (!*buffer)
		return (NULL);
	if (i == 0)
	{
		if (*buffer)
		{
			free(*buffer);
			*buffer = 0;
		}
		return (NULL);
	}
	else if (i == 1)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = 0;
		return (line);
	}
	return (NULL);
}
