/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshapraboth <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:20:56 by malshapraboth     #+#    #+#             */
/*   Updated: 2025/12/15 10:20:57 by malshapraboth    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_present(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	str_arr_len_eof(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i][0] == '\n')
			printf("%c\n", str[i][0]);
		i++;
	}
	return (i);
}

int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("cub3D");
		exit(0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	check_whole_str(char *str)
{
	int		occr;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	occr = 0;
	while (i < len)
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
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
