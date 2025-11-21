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

void	free_tex(t_texture *texture, void *mlx)
{
	if (!texture)
		return ;
	if (texture->path)
		free(texture->path);
	if (texture->img)
		mlx_destroy_image(mlx, texture->img);
	free(texture);
}

void	free_texture(t_textures *texture, void *mlx)
{
	if (!texture)
		return ;
	free_tex(texture->east, mlx);
	free_tex(texture->north, mlx);
	free_tex(texture->south, mlx);
	free_tex(texture->west, mlx);
	free(texture);
}
