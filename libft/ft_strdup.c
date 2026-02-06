/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:59:04 by msisto            #+#    #+#             */
/*   Updated: 2024/01/17 10:50:19 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	size_t	in;
	size_t	cp;

	in = 0;
	cp = 0;
	while (s1[in] != '\0')
		in++;
	r = (char *)malloc((in + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	while (cp < in)
	{
		r[cp] = s1[cp];
		cp++;
	}
	r[cp] = '\0';
	return (r);
}
