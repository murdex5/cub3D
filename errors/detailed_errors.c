/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detailed_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:34:04 by msisto            #+#    #+#             */
/*   Updated: 2026/01/27 14:12:12 by msisto           ###   ########.fr       */
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
	{
		perror("cub3D");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
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
		printf("Error\nFile not found %s\n", path);
		return ;
	}
	if (!read_files(path))
	{
		printf("Error\n Reading %s failed\n", path);
		return ;
	}
}

void	mulitiple_de_msg(char *path1, char *path2)
{
	detailed_err_msg_order(path1);
	detailed_err_msg_order(path2);
}
