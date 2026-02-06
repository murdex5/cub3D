/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:29:42 by msisto            #+#    #+#             */
/*   Updated: 2026/02/04 17:24:47 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_file_type(char *file, char *type)
{
	char	*dot;
	int		i;
	int		j;

	if (!file)
		return (0);
	if (ft_strlen(file) < 5)
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
	if (line[0] != 'F' && line[0] != 'C' && line[len - 1] == '1')
		return (1);
	return (0);
}

int	check_zero(char **map, int k)
{
	size_t	i;

	i = 0;
	if (k == 0 || k == str_arr_len(map))
		return (1);
	while (map[k][i])
	{
		if (map[k][i] == '0')
		{
			if (ft_strlen(map[k - 1]) <= i || ft_strlen(map[k + 1]) <= i)
				return (0);
			if (map[k - 1][i] == ' ' || map[k - 1][i] == '\n')
				return (0);
			if (map[k + 1][i] == ' ' || map[k + 1][i] == '\n')
				return (0);
			if (i > 0 && (map[k][i - 1] == ' ' || map[k][i - 1] == '\n'))
				return (0);
			if (i < ft_strlen(map[k]) && (map[k][i + 1] == ' ' || map[k][i + 1] == '\n'))
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
