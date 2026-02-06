/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:12:48 by msisto            #+#    #+#             */
/*   Updated: 2024/01/19 11:46:16 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int		words;
	size_t	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == sep)
			i++;
		else
		{
			words++;
			while (str[i] != sep && str[i])
				i++;
		}
	}
	return (words);
}

static char	**thesplit(char **res, const char *str, char sep)
{
	size_t	i;
	size_t	len;
	int		w;

	w = -1;
	i = 0;
	len = 0;
	while (++w < count_words(str, sep))
	{
		while (str[i] == sep && str[i])
			i++;
		while (str[i + len] != sep && str[i + len])
			len++;
		res[w] = (char *)malloc((len + 1) * sizeof(char));
		if (!res[w])
			return (NULL);
		ft_memcpy(res[w], &str[i], len);
		res[w][len] = '\0';
		i += len;
		len = 0;
	}
	res[w] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = thesplit(res, s, c);
	return (res);
}
