/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:44:07 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/19 12:44:08 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file_type(char *file, char *type)
{
	char	*dot;
	int		i;
	int		j;

	if (!file)
		return (0);
	dot = malloc(sizeof(char) * 5);
	if (!dot)
		return (0);
	i = (int)ft_strlen(file) - 5;
	j = -1;
	while (file[i] != '\0')
	{
		dot[++j] = file[++i];
	}
	dot[j] = '\0';
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
		return (free(dot), 1);
	else
		return (free(dot), 0);
}

int	check_loaded(t_textures *textures)
{
	if (textures->east->img == NULL || textures->north->img == NULL
		|| textures->south->img == NULL || textures->west->img == NULL)
		return (0);
	else
		return (1);
}

int	check_instances(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len < 2)
		return (0);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		len--;
	if (len == 0)
		return (0);
	if (line[0] == '1' && line[len - 1] == '1')
		return (1);
	return (0);
}

int	check_zero(char **map, char *line, int k)
{
	size_t	i;
	size_t	str_len;
	size_t	prev_len;

	if (k <= 0 || !map[k - 1])
		return (1);
	i = 0;
	str_len = ft_strlen(line);
	prev_len = ft_strlen(map[k - 1]);
	while (i < str_len)
	{
		if (line[i] == ' ')
		{
			if (i < prev_len && map[k - 1][i] == '0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_holes(char **map, char *line, int k)
{
	size_t	i;
	size_t	str_len;
	size_t	prev_len;
	size_t	next_len;

	if (k <= 0 || !map[k - 1] || !map[k + 1])
		return (1);
	i = 0;
	str_len = ft_strlen(line);
	prev_len = ft_strlen(map[k - 1]);
	next_len = ft_strlen(map[k + 1]);
	while (i < str_len)
	{
		if (line[i] == ' ')
		{
			if (i < prev_len && i < next_len && (map[k - 1][i] == '0' || map[k
					- 1][i] == '1') && (map[k + 1][i] == '0' || map[k
					+ 1][i] == '1'))
				return (0);
		}
		i++;
	}
	return (1);
}
