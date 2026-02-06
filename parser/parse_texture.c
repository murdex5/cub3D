/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:56:54 by msisto            #+#    #+#             */
/*   Updated: 2026/01/19 14:37:07 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	assign_paths(char **content, int i, t_texture *texture)
{
	char	**split_result;

	split_result = ft_split(content[i], ' ');
	if (!split_result || !split_result[0])
		return (free_tab((void **)split_result));
	if (!split_result[1])
		return (free_tab((void **)split_result));
	if (ft_strcmp(split_result[0], "NO") == 0)
		texture->north = ft_strdup(split_result[1]);
	else if (ft_strcmp(split_result[0], "SO") == 0)
		texture->south = ft_strdup(split_result[1]);
	else if (ft_strcmp(split_result[0], "WE") == 0)
		texture->west = ft_strdup(split_result[1]);
	else if (ft_strcmp(split_result[0], "EA") == 0)
		texture->east = ft_strdup(split_result[1]);
	if (!check_file_type(split_result[1], ".xpm"))
		return (free_tab((void **)split_result));
	free_tab((void **)split_result);
}

void	get_text_path(t_map *map, t_texture *texture)
{
	int		lines;
	int		i;

	lines = count_lines_arr(map->content);
	i = 0;
	while (i < lines)
	{
		assign_paths(map->content, i, texture);
		i++;
	}
	map->content_order = 1;
}

void	parse_textures(t_data *data)
{
	get_text_path(&data->map_info, &data->texture);
}
