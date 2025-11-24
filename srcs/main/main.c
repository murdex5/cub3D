/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:28:23 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/17 14:28:25 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map *map;
	void *mlx;
	if (argc != 2)
		return (ft_putstr_fd("Error\n Usage: ./cub3D <filename> \n", 1), 1);
	mlx = mlx_init();
	map = parse_map(argv[1], mlx);
	if (!map)
		return (free_mlx(mlx), 1);
	free_map(map, mlx);
	free_mlx(mlx);
	return (0);
}
