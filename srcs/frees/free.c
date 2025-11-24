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

void	free_char_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
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