/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:47:38 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/21 13:47:39 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(char *color_arr)
{
	char	**color_split;
	int		color;
	int		r;
	int		g;
	int		b;

	color_split = ft_split(color_arr, ',');
	if (!color_split || !color_split[0])
		return (free_char_array(color_split), -1);
	if (str_arr_len(color_split) != 3)
		return (free_char_array(color_split), -1);
	r = ft_atoi(color_split[0]);
	g = ft_atoi(color_split[1]);
	b = ft_atoi(color_split[2]);
	color = (r << 16) | (g << 8) | b;
	free_char_array(color_split);
	return (color);
}

int	assign_colors(char **content, int i, t_map *map)
{
	char	**split_result;

	split_result = ft_split(content[i], ' ');
	if (!split_result || !split_result[0])
		return (free_char_array(split_result), 0);
	if (ft_strcmp(split_result[0], "F") == 0)
		map->floor_color = get_color(split_result[1]);
	else if (ft_strcmp(split_result[0], "C") == 0)
		map->ceiling_color = get_color(split_result[1]);
	free_char_array(split_result);
	map->lst_itr = i + 1;
	return (1);
}
