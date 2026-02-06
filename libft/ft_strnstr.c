/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:44:35 by msisto            #+#    #+#             */
/*   Updated: 2024/01/17 10:46:57 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;

	if (!*needle)
		return ((char *)haystack);
	while (len > 0 && *haystack)
	{
		c = 0;
		while (c < len && needle[c] && haystack[c] == needle[c])
			c++;
		if (needle[c] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
