/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:29:39 by msisto            #+#    #+#             */
/*   Updated: 2026/02/06 12:39:24 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_top_bot(t_map *map_info)
{
	int	j;
	int	i;

	j = 0;
	i = map_info->lst_itr;
	while (map_info->content[i][j])
	{
		if (map_info->content[map_info->lst_itr][j] != '1'
			&& map_info->content[map_info->lst_itr][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	while (map_info->content[map_info->lst_itr + map_info->height - 1][j])
	{
		if (map_info->content[map_info->lst_itr + map_info->height - 1][j] != '1'
			&& map_info->content[map_info->lst_itr + map_info->height - 1][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	check_surrounded(t_map *map_info)
{
	int	i;
	int	len;

	if (!map_info->content)
		return (0);
	i = map_info->lst_itr;
	if (!check_top_bot(map_info))
		return (0);
	while (i < map_info->lst_itr + map_info->height)
	{
		len = ft_strlen(map_info->content[i]);
		if (map_info->content[i][0] != '1' && map_info->content[i][0] != ' ')
			return (0);
		if (len > 0)
		{
			if (map_info->content[i][len - 1] != '1' && map_info->content[i][len
				- 1] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_chars(t_map *map_info)
{
	int		i;
	size_t	j;
	int		map_len;
	char	c;

	i = map_info->lst_itr;
	map_len = str_arr_len(map_info->content);
	while (i < map_len)
	{
		j = 0;
		while (j < ft_strlen(map_info->content[i]))
		{
			c = map_info->content[i][j];
			if (!check_one(c))
			{
				printf("Invalid char: %c\n", c);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_data *data, t_map *map_info)
{
	mod_lst_it(map_info);
	get_h_w(map_info);
	if (map_info->content_order != 2)
		free_exit(data, 3, NULL);
	if (!check_surrounded(map_info))
		free_n_err_file(data, 3, "The maps is not surrounded", MAP_MSG);
	if (!check_valid_chars(map_info))
		free_n_err_file(data, 3, NULL, MAP_MSG);
	if (!has_holes(map_info->content))
		free_n_err_file(data, 3, "Can not contain empty spaces inside the map\n", MAP_MSG);
	map_info->content_order = 3;
	return ;
}

int	has_holes(char **map)
{
	int	arr_len;
	int	i;

	arr_len = str_arr_len_eof(map);
	i = 0;
	while (i < arr_len)
	{
		if (check_instances(map[i]))
		{
			if (!check_zero(map, i))
			return (0);
		}
		i++;
	}
	return (1);
}
