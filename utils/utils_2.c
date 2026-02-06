/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:40:12 by msisto            #+#    #+#             */
/*   Updated: 2026/01/14 13:04:52 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

int	is_present(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
