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

t_player	*init_player(void)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		return (NULL);
	player->dir_x = -1;
	player->dir_y = -1;
	player->pos_x = -1;
	player->pos_y = -1;
	return (player);
}
void	set_player_pos(size_t x, size_t y, t_player *player)
{
	player->pos_x = x;
	player->pos_y = y;
}

void	get_player_pos_pl(t_map *map, t_player *player)
{
	int		map_len;
	int		i;
	size_t	temp_len;
	size_t	j;

	i = map->lst_itr;
	map_len = str_arr_len(map->content);
	temp_len = 0;
	while (i < map_len)
	{
		j = 0;
		temp_len = ft_strlen(map->content[i]);
		while (j < temp_len)
		{
			if (is_present(map->content[i][j]))
				return (set_player_pos(j, (size_t)i, player));
			j++;
		}
		i++;
	}
}

t_player	*parse_player(t_map *map)
{
	t_player *player;

	player = init_player();
	if (!player)
		return (err_msg_std("Failed to Init player"), NULL);
	get_player_pos_pl(map, player);
	if (player->pos_x < 0 || player->pos_y < 0)
		return (free(player), err_msg_std("Failed to parse player"), NULL);
	return (player);
}
