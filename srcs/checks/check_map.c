/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:04:19 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/20 13:04:20 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_surrounded(t_map *map)
{
	int	i;

	i = 0;
	while (map->content[i])
	{
		if (map->content[i][0] != '1')
			return (0);
		if (map->content[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	if (!check_one(map->content[0], '0'))
		return (0);
	else if (!check_one(map->content[map->height - 1], '0'))
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
    if (!check_surrounded(map))
        return (err_msg_std("The map is not surrounded"), 0);
}
