/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:50:43 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/24 14:50:45 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mod_lst_it(t_map *map)
{
	int		i;
	size_t	j;
	int		map_len;

	i = map->lst_itr;
	map_len = str_arr_len(map->content);
	while (i < map_len)
	{
		j = 0;
		while (j < ft_strlen(map->content[i]))
		{
			if (map->content[i][j] == '1' || map->content[i][j] == '0')
			{
				map->lst_itr = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_h_w(t_map *map)
{
	int	i;
	int	map_len;
	int	h;
	int	w;
	int	k;

	i = map->lst_itr;
	w = 0;
	h = 0;
	map_len = str_arr_len(map->content);
	while (i < map_len)
	{
		k = ft_strlen(map->content[i]);
		if (k > w)
			w = k;
		if (check_whole_str(map->content[i]))
			h++;
		i++;
	}
	map->width = w;
	map->height = h;
}

int	check_one(char c)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W')
		return (0);
	return (1);
}

int	check_just_chars(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	set_map_details(t_map *map, char **map_copy, int j)
{
	map_copy[j] = NULL;
	free_char_array(map->content);
	map->content = NULL;
	map->content = map_copy;
	map->height = j;
}
