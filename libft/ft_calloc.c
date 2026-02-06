/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:08:58 by msisto            #+#    #+#             */
/*   Updated: 2024/01/18 11:24:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned long	len;

	mem = NULL;
	len = (unsigned long)size * (unsigned long)count;
	if (count && size && count > (4294967295U / size))
		return (0);
	mem = malloc(len);
	if (!mem)
		return (NULL);
	ft_bzero(mem, len);
	return (mem);
}
