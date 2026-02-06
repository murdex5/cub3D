/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:16:24 by msisto            #+#    #+#             */
/*   Updated: 2024/01/16 12:56:38 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	while ((i + c + 1) < dstsize && src[c] != '\0')
	{
		dst[i + c] = src[c];
		c++;
	}
	dst[i + c] = '\0';
	return (i + ft_strlen(src));
}
