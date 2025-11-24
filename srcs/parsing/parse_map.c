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
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->height = 0;
	map->width = 0;
	map->start_x = -1;
	map->start_y = -1;
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

t_map	*map_pop(t_map *map, char *path, void *mlx)
{
	int	lines;
	int	i;

	i = 0;
	lines = count_lines(path);
	map->content = ft_calloc(sizeof(char *), (lines + 1));
	map->content[lines] = NULL;
	if (!map->content)
		return (free_char_array(map->content), NULL);
	if (!read_map_files(map, path))
		return (free_char_array(map->content), NULL);
	map->textures = parse_textures(map, mlx);
	while (i < lines)
	{
		if (map->floor_color == -1 || map->ceiling_color == -1)
		{
			if (map->content[i][0] == 'F' || map->content[i][0] == 'C')
			{
				if (!assign_colors(map->content, i, map))
					return (err_msg_std("Invalid color format"), free_map(map,
							mlx), NULL);
			}
		}
		i++;
	}
	return (map);
}

void	set_pos(size_t i, size_t j, t_map *map)
{
	map->start_y = i;
	map->start_x = j;
	map->playr_count++;
}

int	get_player_pos(t_map *map)
{
	int		map_len;
	int		i;
	size_t	temp_len;
	size_t	j;

	i = map->lst_itr;
	map_len = str_arr_len(map->content);
	temp_len = 0;
	while (i < map_len)
	{
		j = 0;
		temp_len = ft_strlen(map->content[i]);
		while (j < temp_len)
		{
			if (is_present(map->content[i][j]))
				set_pos(i, j, map);
			j++;
		}
		i++;
	}
	if (map->playr_count > 1)
		return (0);
	return (1);
}

t_map	*parse_map(char *path, void *mlx)
{
	t_map	*map;

	if (!check_file_type(path, ".cub"))
		return (NULL);
	map = init_map();
	if (!map)
		return (printf("Couldn't initialize the map\n"), NULL);
	map = map_pop(map, path, mlx);
	if (!map)
		return (NULL);
	if (!check_map(map))
		return (free_map(map, mlx), NULL);
	if (!get_player_pos(map))
		return (free_map(map, mlx), err_msg_std("parsing failed"), NULL);
	
	return (map);
}
