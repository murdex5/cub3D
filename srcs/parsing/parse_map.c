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

t_map	*parse_map(char *path)
{
	t_map	*map;

	if (!check_file_type(path, ".cub"))
		return (NULL);
	map = init_map();
	if (!map)
		return (free_error("Couldn't initialize the map", map), NULL);
}
