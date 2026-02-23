/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datasetup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:15:04 by msisto            #+#    #+#             */
/*   Updated: 2026/02/09 12:35:01 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	map_setup(t_map *map_info)
{
	map_info->content = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->lst_itr = 0;
	map_info->content_order = 0;
	map_info->player_count = 0;
}

void	ray_set(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->perpwalldist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	player_setup(t_player *player)
{
	player->dir = '\0';
	player->moved = 0;
	player->pos_x = -1.0;
	player->pos_y = -1.0;
	player->dir_x = -1.0;
	player->dir_y = -1.0;
	player->plane_x = -1.0;
	player->plane_y = -1.0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	data_setup(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	player_setup(&data->player);
	texture_setup(&data->texture);
	data->texture_pixels = NULL;
	data->textures = NULL;
	data->map = NULL;
}
