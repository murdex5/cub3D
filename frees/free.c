/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:12:45 by msisto            #+#    #+#             */
/*   Updated: 2026/02/06 13:09:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_exit(t_data *data, int lvl, char *msg)
{
	if (msg)
		perror(msg);
	on_key_press_exit(data, lvl);
	exit(1);
}

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

int	free_n_return(char **str, char *temp, char *msg)
{
	free_tab((void **)str);
	if (temp)
		free(temp);
	temp = NULL;
	if (msg)
		err_msg_std(msg);
	return (0);
}

void	free_err_file(t_data *data, int lvl, char *msg, char *f_p)
{
	if (msg)
		err_msg_std(msg);
	detailed_err_msg_order(f_p);
	free_exit(data, lvl, NULL);
}
