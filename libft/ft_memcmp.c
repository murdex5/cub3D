/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:29:09 by msisto            #+#    #+#             */
/*   Updated: 2024/01/11 09:49:49 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			in;
	int				re;

	in = 0;
	while (in < n)
	{
		if (((unsigned char *)s1)[in] != ((unsigned char *)s2)[in])
		{
			re = ((unsigned char *)s1)[in] - ((unsigned char *)s2)[in];
			return (re);
		}
		in++;
	}
	return (0);
}
