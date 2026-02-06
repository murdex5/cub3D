/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:43:08 by msisto            #+#    #+#             */
/*   Updated: 2024/01/15 14:42:58 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = -1;
	while (src[++i] && (i + 1) < dstsize)
		dst[i] = src[i];
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
