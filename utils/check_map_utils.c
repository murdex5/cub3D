/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:34:51 by msisto            #+#    #+#             */
/*   Updated: 2026/01/14 12:41:58 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	mod_lst_it(t_map *map_info)
{
	int		i;
	size_t	j;
	int		map_len;

	i = map_info->lst_itr;
	map_len = str_arr_len(map_info->content);
	while (i < map_len)
	{
		j = 0;
		while (j < ft_strlen(map_info->content[i]))
		{
			if (map_info->content[i][j] == '1'
					|| map_info->content[i][j] == '0')
			{
				map_info->lst_itr = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_h_w(t_map *map_info)
{
	int	i;
	int	map_len;
	int	h;
	int	w;
	int	k;

	i = map_info->lst_itr;
	w = 0;
	h = 0;
	map_len = str_arr_len(map_info->content);
	while (i < map_len)
	{
		k = ft_strlen(map_info->content[i]);
		if (k > w)
			w = k;
		if (check_whole_str(map_info->content[i]))
			h++;
		i++;
	}
	map_info->width = w;
	map_info->height = h;
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
