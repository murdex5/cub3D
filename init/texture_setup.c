/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:23:38 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 12:35:42 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texture.size * data->texture.size);
	if (!buffer)
		free_exit(data, 3, RED"Error\nCould not allocate memory"RESET);
	y = 0;
	while (y < data->texture.size)
	{
		x = 0;
		while (x < data->texture.size)
		{
			buffer[y * data->texture.size + x]
				= tmp.addr[y * data->texture.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		free_exit(data, 3, RED"Error\nCould not allocate memory"RESET);
	data->textures[NORTH] = xpm_to_img(data, data->texture.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texture.south);
	data->textures[EAST] = xpm_to_img(data, data->texture.east);
	data->textures[WEST] = xpm_to_img(data, data->texture.west);
}

void	texture_setup(t_texture *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = 64;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
