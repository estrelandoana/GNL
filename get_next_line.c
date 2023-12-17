/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 06:37:11 by apaula-l          #+#    #+#             */
/*   Updated: 2023/12/17 12:55:00 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_ft_building_line(int fd, char *over, char *buffer);
static char	*_ft_over_line(char *line);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*over;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(over);
		free(buffer);
		over = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	line = _ft_building_line(fd, over, buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	over = _ft_over_line(line);
	return (line);
}

static char	*_ft_building_line(int fd, char *over, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(over);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (over == NULL)
			over = ft_strdup("");
		tmp = over;
		over = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (over);
}

static char	*_ft_over_line(char *line_buffer)
{
	ssize_t	i;
	char	*over;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
	{
		i++;
	}
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
	{
		return (NULL);
	}
	over = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*over == 0)
	{
		free(over);
		over = NULL;
	}
	line_buffer[i + 1] = 0;
	return (over);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
