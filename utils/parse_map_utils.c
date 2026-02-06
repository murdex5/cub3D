/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:36:32 by msisto            #+#    #+#             */
/*   Updated: 2026/01/14 12:41:22 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_for_map(t_map *map_info, int lines, int i)
{
	size_t	j;
	size_t	line_len;

	if (i == lines)
		return (0);
	while (i < lines)
	{
		j = 0;
		line_len = ft_strlen(map_info->content[i]);
		while (j < line_len)
		{
			if (check_just_chars(map_info->content[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
