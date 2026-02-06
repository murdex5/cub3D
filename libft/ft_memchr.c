/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:46:41 by msisto            #+#    #+#             */
/*   Updated: 2024/01/11 09:45:09 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			in;

	in = 0;
	while (in < n)
	{
		if (((unsigned char *)s)[in] == (unsigned char)c)
		{
			return ((void *)(s + in));
		}
		in++;
	}
	return (NULL);
}
