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
	if (map->playr_count == 0)
		return (err_msg_std("\nCouldn't find the player in the map\n"),
			detailed_err_msg_order(MAP_MSG), 0);
	return (1);
}

int	check_for_map(t_map *map, int lines, int i)
{
	size_t	j;
	size_t	line_len;

	if (i == lines)
		return (0);
	while (i < lines)
	{
		j = 0;
		line_len = ft_strlen(map->content[i]);
		while (j < line_len)
		{
			if (check_just_chars(map->content[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	set_colors(t_map *map, int lines)
{
	int	i;
	int	k;

	i = 0;
	if (map->content_order != 1)
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	k = 0;
	while (i < lines)
	{
		if (map->floor_color == -1 || map->ceiling_color == -1)
		{
			if (map->content[i][0] == 'F' || map->content[i][0] == 'C')
			{
				if (!assign_colors(map->content, i, map))
					return (detailed_err_msg_order(COLOR_MSG), 0);
				k = i + 1;
			}
		}
		i++;
	}
	if (map->ceiling_color < 0 || map->floor_color < 0)
		return (detailed_err_msg_order(COLOR_NEG), 0);
	if (!check_for_map(map, lines, k))
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	map->content_order = 2;
	return (1);
}
