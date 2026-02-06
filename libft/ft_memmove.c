/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:57:16 by msisto            #+#    #+#             */
/*   Updated: 2024/01/15 13:40:47 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	if ((unsigned char *)dst > (const unsigned char *)src)
	{
		while (len-- > 0)
		{
			((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
		}
	}
	else
	{
		dst = ft_memcpy(dst, src, len);
	}
	return (dst);
}
