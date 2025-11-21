/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:41:02 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/20 12:41:06 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->content = NULL;
	map->textures = NULL;
	map->ceiling_color = 0;
	map->floor_color = 0;
	map->height = 0;
	map->width = 0;
	map->start_dir = 0;
	map->start_x = 0;
	map->start_y = 0;
	return (map);
}
int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("cub3D");
		exit(0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	read_map_files(t_map *map, char *file)
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
		map->content[i] = ft_strdup(line);
		free(line);
		if (!map->content[i])
			return (free_n_return(map->content, NULL, NULL), 0);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

t_map	*map_pop(t_map *map, char *path)
{
	int	lines;

	lines = count_lines(path);
	map->content = ft_calloc(sizeof(char *), (lines + 1));
	map->content[lines] = NULL;
	if (!map->content)
		return (err_msg_std("MEm allc fail add a free func for mapo\n"),
			free_char_arra(map->content), NULL);
	if (!read_map_files(map, path))
		return (err_msg_std("MEm allc fail add a free func for mapo\n"),
			free_char_arra(map->content), NULL);
	map->textures = parse_textures(map);
	return (map);
}

t_map	*parse_map(char *path)
{
	t_map	*map;

	if (!check_file_type(path, ".cub"))
		return (NULL);
	map = init_map();
	if (!map)
		return (printf("Couldn't initialize the map\n"), NULL);
	map = map_pop(map, path);
	if (!map)
		return (NULL);
	return (map);
}
