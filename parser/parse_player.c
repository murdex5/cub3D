/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:16:14 by msisto            #+#    #+#             */
/*   Updated: 2026/02/02 12:57:33 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_player_pos_pl(t_player *player, char **map)
{
	int		i;
	size_t	temp_len;
	size_t	j;

	i = 0;
	temp_len = 0;
	while (i < str_arr_len(map))
	{
		j = 0;
		temp_len = ft_strlen(map[i]);
		while (j < temp_len)
		{
			if (is_present(map[i][j]))
			{
				if (ft_strchr("NSEW", map[i][j]))
					player->dir = map[i][j];
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
	get_player_pos_pl(&data->player, data->map);
}
