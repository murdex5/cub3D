/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:13:52 by msisto            #+#    #+#             */
/*   Updated: 2024/01/17 12:47:04 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	size;

	size = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (size < n)
	{
		((unsigned char *)dst)[size] = ((const unsigned char *)src)[size];
		size++;
	}
	return (dst);
}
