/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:13:27 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/20 13:13:28 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int coutn_lines_arr(char **arr)
{
    int i;
    if (!arr)
        return (0);
    i = 0;
    while (arr[i])
        i++;
    return (i);
}

t_textures	*init_textures(void)
{
	t_textures	*textures;

	textures = ft_calloc(sizeof(t_textures), 1);
	if (!textures)
		return (err_msg_std("Couldn't load textures"), NULL);
	// Paths <chsr *>
	textures->east_path = NULL;
	textures->north_path = NULL;
	textures->south_path = NULL;
	textures->west_path = NULL;
	// Textures
	textures->east_xpm = NULL;
	textures->north_xpm = NULL;
	textures->south_xpm = NULL;
	textures->west_xpm = NULL;
	return (textures);
}

t_textures	*assign_paths(char **content, int i, t_textures *textures)
{
	char	**split_result;

	split_result = ft_split(content[i], " ");
	if (!split_result)
		return (NULL);
	if (ft_strncmp(split_result[0], "NO", ft_strlen("NO")) == 0)
		textures->north_path = ft_strdup(split_result[1]);
	else if (ft_strncmp(split_result[0], "SO", ft_strlen("NO")) == 0)
		textures->south_path = ft_strdup(split_result[1]);
	else if (ft_strncmp(split_result[0], "WE", ft_strlen("NO")) == 0)
		textures->west_path = ft_strdup(split_result[1]);
	else if (ft_strncmp(split_result[0], "EA", ft_strlen("NO")) == 0)
		textures->east_path = ft_strdup(split_result[1]);
	free_char_arra(split_result);
	return (textures);
}

t_textures	*get_tex_path(t_map *map, t_textures *textures)
{
	int		lines;
	int		i;
	char	**content;

	content = map->content;
	lines = count_lines_arr(content);
	i = 0;
	while (i < lines)
	{
		assign_paths(content, i, textures);
		i++;
	}
	return (textures);
}
t_textures	*parse_textures(char *map)
{
	t_textures *textures;

	textures = init_textures();
	if (!textures)
		return (NULL);
    textures = get_tex_path(map, textures);
	return (NULL);
}