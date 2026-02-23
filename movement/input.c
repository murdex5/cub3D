/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:03:30 by msisto            #+#    #+#             */
/*   Updated: 2026/01/26 13:14:26 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit(data);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w)
		data->player.move_y = 1;
	if (key == XK_a)
		data->player.move_x = -1;
	if (key == XK_s)
		data->player.move_y = -1;
	if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit(data);
	if (key == XK_Left && data->player.rotate == -1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate == 1)
		data->player.rotate = 0;
	if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	return (0);
}

void	input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quit, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, data);
}
