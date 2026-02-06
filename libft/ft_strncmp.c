/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:26:42 by msisto            #+#    #+#             */
/*   Updated: 2024/01/16 12:41:11 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	int				d;

	i = 0;
	d = 0;
	if (!n)
		return (d);
	while (str1[i] == str2[i] && i < (n - 1) && str1[i] && str2[i])
		i++;
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
