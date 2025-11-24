/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:40:12 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/24 14:40:14 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
