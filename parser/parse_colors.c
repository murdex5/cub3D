/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:28:40 by msisto            #+#    #+#             */
/*   Updated: 2026/02/06 15:15:59 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	rgb_check(char *num)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(num))
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	*get_color(char *line)
{
	char	**color_split;
	int		*rgb;

	color_split = ft_split(line, ',');
	if (!color_split || !color_split[0])
		return (free_tab((void **)color_split), NULL);
	if (str_arr_len(color_split) != 3)
		return (free_tab((void **)color_split), NULL);
	if (rgb_check(color_split[0]) || rgb_check(color_split[1])
		|| rgb_check(color_split[2]))
		return (free_tab((void **)color_split), NULL);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (free_tab((void **)color_split), NULL);
	rgb[0] = ft_atoi(color_split[0]);
	rgb[1] = ft_atoi(color_split[1]);
	rgb[2] = ft_atoi(color_split[2]);
	free_tab((void **)color_split);
	if ((rgb[0] < 0 || rgb[0] > 255) || (rgb[1] < 0 || rgb[1] > 255)
		|| (rgb[2] < 0 || rgb[2] > 255))
		return (detailed_err_msg_order(COLOR_NEG), free(rgb), NULL);
	return (rgb);
}

void	assign_colors(t_texture *tex, char *line)
{
	char	**split_result;

	split_result = ft_split(line, ' ');
	if (split_result[0][0] == 'C')
		tex->ceiling = get_color(split_result[1]);
	else
		tex->floor = get_color(split_result[1]);
	free_tab((void **)split_result);
}

unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	if (!rgb_tab)
		return (0);
	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	set_colors(t_texture *tex, t_map *map_info, int lines)
{
	int	i;
	int	k;

	i = 0;
	if (map_info->content_order != 1)
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	k = 0;
	while (i < lines)
	{
		if (map_info->content[i][0] == 'C' || map_info->content[i][0] == 'F')
		{
			assign_colors(tex, map_info->content[i]);
			map_info->lst_itr = i + 1;
			k = i + 1;
		}
		i++;
	}
	tex->hex_floor = convert_rgb_to_hex(tex->floor);
	tex->hex_ceiling = convert_rgb_to_hex(tex->ceiling);
	if (!check_for_map(map_info, lines, k))
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	map_info->content_order = 2;
	return (1);
}
