/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:13:26 by msisto            #+#    #+#             */
/*   Updated: 2024/01/25 10:44:26 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = (unsigned int)ft_strlen(s) + 1;
	str = ft_calloc(i, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		str[i] = (*f)(i, (char)s[i]);
	}
	return (str);
}
