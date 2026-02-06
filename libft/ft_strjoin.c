/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:36:29 by msisto            #+#    #+#             */
/*   Updated: 2024/01/17 14:59:01 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		c;
	int		len;
	char	*fstr;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		c = ft_strlen(s2);
		fstr = (char *)malloc((i + c + 1) * sizeof(char));
		if (fstr == NULL)
			return (NULL);
		len = -1;
		while (s1[++len])
			fstr[len] = s1[len];
		len = -1;
		while (s2[++len])
		{
			fstr[i] = s2[len];
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
