/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:46:55 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 12:32:53 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	t_struct_free(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->west)
		free(texture->west);
	if (texture->east)
		free(texture->east);
	if (texture->floor)
		free(texture->floor);
	if (texture->ceiling)
		free(texture->ceiling);
}

void	on_key_press_exit(t_data *data, int lvl)
{
	if (!data)
		exit (1);
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_tab((void **)data->map);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	if (data->textures)
		free_tab((void **)data->textures);
	if (lvl >= 2 && data->map_info.content)
		free_tab((void **)data->map_info.content);
	if (lvl >= 3)
		t_struct_free(&data->texture);
}

int	quit(t_data *data)
{
	printf(GREEN "leaving the game\n" RESET);
	free_exit(data, 3, NULL);
	return (0);
}
