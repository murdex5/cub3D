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
	{
		free(dot);
		return (1);
	}
	else
	{
		free(dot);
		return (0);
	}
}

int	check_loaded(t_textures *textures)
{
	// if (textures->east->img && textures->north->img && textures->south->img
	// 	&& textures->west->img)
	if (textures->east->img == NULL || textures->north->img == NULL || textures->south->img == NULL
		|| textures->west->img == NULL)
		return (0);
	else
		return (1);
}