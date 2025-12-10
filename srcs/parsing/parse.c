/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:43:58 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/19 12:43:59 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (err_msg_std("T_data allocation failed"), NULL);
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->player = NULL;
	data->win_height = 0;
	data->win_width = 0;
	return (data);
}
int	init_mlx(void **mlx, void **win, int h, int w)
{
	*mlx = mlx_init();
	if (!mlx)
		return (err_msg_std("Initializing mlx failed"), 0);
	*win = mlx_new_window(*mlx, w, h, "cub3D");
	if (!win)
		return (err_msg_std("Initializing win mlx failed"), free_mlx(*mlx), 0);
	return (1);
}

t_data	*parse_data(char *path)
{
	t_data	*data;

	data = init_data();
	if (!data)
		return (NULL);
	data->win_height = SCREEN_HEIGHT;
	data->win_width = SCREEN_WIDTH;
	if (!init_mlx(&data->mlx, &data->win, SCREEN_HEIGHT, SCREEN_WIDTH))
		return (free_t_data(data), NULL);
	data->map = parse_map(path, data->mlx);
	if (!data->map)
		return (free_t_data(data), NULL);
	data->textures = data->map->textures;
	data->player = parse_player(data->map);
	if (!data->player)
		return (free_t_data(data), NULL);
	return (data);
}
