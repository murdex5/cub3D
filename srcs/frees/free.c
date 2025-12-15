/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:54:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/20 13:54:36 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_n_return(char **str, char *temp, char *msg)
{
	free_char_array(str);
	if (temp)
		free(temp);
	temp = NULL;
	if (msg)
		err_msg_std(msg);
	return (0);
}

void	free_mlx(void *mlx)
{
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	else
		return ;
}

void	free_win(void *win, void *mlx)
{
	if (!win)
		return ;
	mlx_destroy_window(mlx, win);
	win = NULL;
}

void	free_player(t_player *player)
{
	if (!player)
		return ;
	free(player);
}

void	free_t_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map && data->mlx)
		free_map(data->map, data->mlx);
	if (data->player)
		free_player(data->player);
	if (data->win)
		free_win(data->mlx, data->win);
	if (data->mlx)
		free_mlx(data->mlx);
	free(data);
}
