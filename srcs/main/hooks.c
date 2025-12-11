/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshapraboth <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:05:31 by malshapraboth     #+#    #+#             */
/*   Updated: 2025/12/11 13:05:33 by malshapraboth    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	on_key_press_exit(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
	{
		free_map(data->map, data->mlx);
		data->map = NULL;
	}
	if (data->player)
	{
		free_player(data->player);
		data->player = NULL;
	}
	data->textures = NULL;
	if (data->mlx)
	{
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	free(data);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
	{
		on_key_press_exit(data);
		exit(0);
	}
	return (0);
}
