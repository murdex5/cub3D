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

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->content = NULL;
	map->textures = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->height = 0;
	map->width = 0;
	map->start_x = -1;
	map->start_y = -1;
	map->content_order = 0;
	return (map);
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

t_map	*map_pop(t_map *map, char *path, void *mlx)
{
	int	lines;

	lines = count_lines(path);
	map->content = ft_calloc(sizeof(char *), (lines + 1));
	map->content[lines] = NULL;
	if (!map->content)
		return (free_char_array(map->content), NULL);
	char *debug = DEBUG;
	if (!read_map_files(map, path))
		return (free_char_array(map->content), NULL);
	map->textures = parse_textures(map, mlx);
	if (!map->textures)
		return (free_map(map, mlx), detailed_err_msg_order(TEXTURE_MSG), NULL);
	if (!set_colors(map, lines))
		return (free_map(map, mlx), NULL);
	printf("%s after map parse_textures\n", debug);
	return (map);
}

int	get_just_map(t_map *map)
{
	char	**map_copy;
	int		arr_len;
	int		i;
	int		j;

	i = map->lst_itr;
	arr_len = str_arr_len(map->content);
	map_copy = ft_calloc(sizeof(char *), map->height + 1);
	if (!map_copy)
		return (0);
	map_copy[map->height] = NULL;
	j = 0;
	while (i < arr_len)
	{
		map_copy[j] = ft_strdup(map->content[i]);
		if (!map_copy[j])
			return (free_char_array(map_copy), 0);
		i++;
		j++;
	}
	free_char_array(map->content);
	map->content = NULL;
	map->content = map_copy;
	return (1);
}

t_map	*parse_map(char *path, void *mlx)
{
	t_map		*map;
	struct stat	buffer;

	if (!check_file_type(path, ".cub"))
		return (NULL);
	if (stat(path, &buffer) != 0)
	{
		printf("Error\nFile not found %s\n", path);
		return (0);
	}
	map = init_map();
	if (!map)
		return (printf("Couldn't initialize the map\n"), NULL);
	map = map_pop(map, path, mlx);
	if (!map)
		return (free_map(map, mlx), NULL);
	if (map->ceiling_color < 0 || map->floor_color < 0)
		return (free_map(map, mlx), err_msg_std("Failed to set Color"), NULL);
	if (!check_map(map))
		return (free_map(map, mlx), NULL);
	if (!get_player_pos(map))
		return (free_map(map, mlx), err_msg_std("Coulnd't find the player in the map"), NULL);
	if (!get_just_map(map))
		return (free_map(map, mlx), err_msg_std("parsing failed"), NULL);
	return (map);
}
