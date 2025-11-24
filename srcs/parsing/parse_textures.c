/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:13:27 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/20 13:13:28 by kadferna         ###   ########.fr       */
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

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = ft_calloc(sizeof(t_texture), 1);
	if (!texture)
		return (err_msg_std("Couldn't load texture"), NULL);
	texture->img = NULL;
	texture->path = NULL;
	texture->img_height = 0;
	texture->img_width = 0;
	return (texture);
}

t_textures	*init_textures(void)
{
	t_textures	*textures;

	textures = ft_calloc(sizeof(t_textures), 1);
	if (!textures)
		return (err_msg_std("Couldn't load textures"), NULL);
	textures->east = init_texture();
	textures->north = init_texture();
	textures->south = init_texture();
	textures->west = init_texture();
	if (!textures->east || !textures->north || !textures->south
		|| !textures->west)
		return (err_msg_std("Failed allocating textures"), NULL);
	return (textures);
}

t_textures	*assign_paths(char **content, int i, t_textures *textures)
{
	char	**split_result;

	split_result = ft_split(content[i], ' ');
	if (!split_result || !split_result[0])
		return (free_char_array(split_result), NULL);
	if (!split_result)
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

t_textures	*get_tex_path(t_map *map, t_textures *textures)
{
	int		lines;
	int		i;
	char	**content;

	content = map->content;
	lines = count_lines_arr(content);
	i = 0;
	while (i < lines)
	{
		if (!check_if_null_text(textures))
		{
			if (!assign_paths(content, i, textures))
				return (err_msg_std("Parsing Texture path failed"), NULL);
		}
		i++;
	}
	return (textures);
}

int	load_texture(t_texture *texture, void *mlx)
{
	struct stat	buffer;

	if (stat(texture->path, &buffer) != 0)
	{
		printf("Error\nFile not found %s\n", texture->path);
		return (0);
	}
	texture->img = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->img_width, &texture->img_height);
	if (!texture->img)
	{
		printf("Error: Failed to load XPM: %s\n", texture->path);
		return (0);
	}
	return (1);
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

t_textures	*parse_textures(t_map *map, void *mlx)
{
	t_textures *textures;

	textures = init_textures();
	if (!textures)
		return (NULL);
	if (!get_tex_path(map, textures))
		return (free_texture(textures, mlx), NULL);
	if (!load_textures(textures, mlx))
		return (free_texture(textures, mlx), NULL);
	return (textures);
}