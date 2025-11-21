/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:09:31 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/21 11:09:33 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_tex_path(t_textures *texture)
{
	if (texture->east_path)
		free(texture->east_path);
	if (texture->north_path)
		free(texture->north_path);
	if (texture->south_path)
		free(texture->south_path);
	if (texture->west_path)
		free(texture->west_path);
}

void	free_texture(t_textures *texture)
{
	if (!texture)
		return ;
	free_tex_path(texture);
	free(texture);
}
