/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:21 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:22 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_lines_arr(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_textures	*assign_paths(char **content, int i, t_textures *textures)
{
	char	**split_result;

	split_result = ft_split(content[i], ' ');
	if (!split_result || !split_result[0])
		return (free_char_array(split_result), NULL);
	if (!split_result[1])
		return (NULL);
	if (ft_strcmp(split_result[0], "NO") == 0)
		textures->north->path = ft_strdup(split_result[1]);
	else if (ft_strcmp(split_result[0], "SO") == 0)
		textures->south->path = ft_strdup(split_result[1]);
	else if (ft_strcmp(split_result[0], "WE") == 0)
		textures->west->path = ft_strdup(split_result[1]);
	else if (ft_strcmp(split_result[0], "EA") == 0)
		textures->east->path = ft_strdup(split_result[1]);
	if (!check_file_type(split_result[1], ".xpm"))
		return (free_char_array(split_result), NULL);
	free_char_array(split_result);
	return (textures);
}

int	load_textures(t_textures *textures, void *mlx)
{
	if (!load_texture(textures->east, mlx))
		return (0);
	if (!load_texture(textures->west, mlx))
		return (0);
	if (!load_texture(textures->north, mlx))
		return (0);
	if (!load_texture(textures->south, mlx))
		return (0);
	return (1);
}
