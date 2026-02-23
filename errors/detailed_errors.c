/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detailed_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:34:04 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 13:18:25 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	read_files(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != 0 && line[ft_strlen(line) - 1] == ':')
			printf(GREEN"%s\n"RESET, line);
		else
			printf("%s\n", line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	detailed_err_msg_order(char *path)
{
	struct stat	buffer;

	if (stat(path, &buffer) != 0)
	{
		printf(RED "Error\nFile not found %s\n" RESET, path);
		return ;
	}
	if (!read_files(path))
	{
		printf(RED "Error\n Reading %s failed\n" RESET, path);
		return ;
	}
}
