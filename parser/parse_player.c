/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:16:14 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 11:54:17 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	player_pos(t_map *map_info, t_player *player, char **map)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < str_arr_len(map))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (is_present(map[i][j]))
			{
				if (ft_strchr("NSEW", map[i][j]))
				{
					player->dir = map[i][j];
					map_info->player_count++;
				}
				player->pos_x = (double)j + 0.5;
				player->pos_y = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	parse_player(t_data *data)
{
	player_setup(&data->player);
	player_pos(&data->map_info, &data->player, data->map);
}
