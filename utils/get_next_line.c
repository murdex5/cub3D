/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:08:09 by msisto            #+#    #+#             */
/*   Updated: 2026/01/15 13:09:41 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*get_line(int fd, char *buf, char *buffer)
{
	int		read_count;
	char	*temp;

	read_count = 1;
	while (read_count != 0)
	{
		read_count = read(fd, buf, 50);
		if (read_count == -1)
			return (0);
		buf[read_count] = '\0';
		if (read_count == 0)
			break ;
		if (!buffer)
			buffer = ft_strdup("");
		temp = buffer;
		buffer = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
		temp = NULL;
	}
	return (buffer);
}

char	*clean_up(char *line)
{
	int		count;
	char	*buf;

	if (!line)
		return (NULL);
	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (NULL);
	buf = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!buf)
	{
		line[count + 1] = '\0';
		return (NULL);
	}
	if (*buf == '\0')
	{
		free(buf);
		buf = NULL;
	}
	line[count + 1] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buf;
	char		*line;

	if (fd < 0 || 50 <= 0)
		return (NULL);
	buf = malloc(50 + 1);
	if (!buf)
		return (NULL);
	line = get_line(fd, buf, buffer);
	buffer = clean_up(line);
	free(buf);
	return (line);
}
