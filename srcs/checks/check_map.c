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

int	check_one(char c)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W')
		return (0);
	return (1);
}

int	check_just_chars(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return (0);
}

int check_whole_str(char *str)
{
	int occr;
	size_t i;
	size_t len;

	len = ft_strlen(str);
	i = 0;
	occr = 0;
	while (i < len)
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		else if (check_just_chars(str[i]))
			occr++;
		i++;
	}
	if (occr >= 1)
		return (1);
	else 
		return (0);
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

int	check_top_bot(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	i = map->lst_itr;
	while (map->content[i][j])
	{
		if (map->content[map->lst_itr][j] != '1'
			&& map->content[map->lst_itr][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	while (map->content[map->lst_itr + map->height - 1][j])
	{
		if (map->content[map->lst_itr + map->height - 1][j] != '1'
			&& map->content[map->lst_itr + map->height - 1][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

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

int	check_surrounded(t_map *map)
{
	int	i;
	int	len;

	i = map->lst_itr;
	if (!check_top_bot(map))
		return (0);
	while (i < map->lst_itr + map->height)
	{
		len = ft_strlen(map->content[i]);
		if (map->content[i][0] != '1' && map->content[i][0] != ' ')
			return (0);
		if (len > 0)
		{
			if (map->content[i][len - 1] != '1' && map->content[i][len
				- 1] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_chars(t_map *map)
{
	int		i;
	size_t	j;
	int		map_len;
	char	c;

	i = map->lst_itr;
	map_len = str_arr_len(map->content);
	while (i < map_len)
	{
		j = 0;
		while (j < ft_strlen(map->content[i]))
		{
			c = map->content[i][j];
			if (!check_one(c))
			{
				printf("Error\nInvalid char: %c\n", c);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	mod_lst_it(map);
	get_h_w(map);
	if (!check_surrounded(map))
		return (err_msg_std("The map is not surrounded"), 0);
	if (!check_valid_chars(map))
		return (0);
	return (1);
}
