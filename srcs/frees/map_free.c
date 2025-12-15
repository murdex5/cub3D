/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:58:29 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/21 10:58:30 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map(t_map *map, void *mlx)
{
	if (!map)
		return ;
	if (map->content)
		free_char_array(map->content);
	if (map->textures)
		free_texture(map->textures, mlx);
	free(map);
}

void	free_char_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
