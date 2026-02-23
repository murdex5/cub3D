/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:53:24 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 12:36:59 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parse_data(t_data *data, char *path)
{
	data_setup(data);
	mlx_setup(data);
	parse_map(data, path);
	parse_player(data);
	if (data->map_info.player_count > 1)
		free_exit(data, 3, RED"Error\ntoo many players\n"RESET);
	if (data->player.dir == '\0')
		free_exit(data, 3, RED"Error\nNo player found\n"RESET);
}
