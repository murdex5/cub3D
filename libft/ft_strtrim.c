/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:33:02 by msisto            #+#    #+#             */
/*   Updated: 2024/01/18 14:02:03 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char val, const char *set)
{
	while (*set)
	{
		if (*set == val)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	len = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	while (end > start && char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[len++] = s1[start++];
	str[len] = '\0';
	return (str);
}
