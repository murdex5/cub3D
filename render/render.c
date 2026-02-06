/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:19:34 by msisto            #+#    #+#             */
/*   Updated: 2026/01/23 14:26:38 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->texture.hex_ceiling);
	else if (y < data->win_height -1)
		set_image_pixel(image, x, y, data->texture.hex_floor);
}

void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	img_setup(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

void	render_raycast(t_data *data)
{
	init_texture_pixels(data);
	ray_set(&data->ray);
	raycasting(&data->player, data);
	render_frame(data);
}

void	render_images(t_data *data)
{
	render_raycast(data);
}

int	render(t_data *data)
{
	data->player.moved += move_player(data);
	if (data->player.moved == 0)
		return (0);
	render_images(data);
	return (0);
}
