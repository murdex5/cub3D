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
	if (argc != 2)
		return (ft_putstr_fd("Error\n Usage: ./cub3D <filename> \n", 1), 1);
	map = parse_map(argv[1]);
	if (!map)
		return (1);
	return (0);
}
