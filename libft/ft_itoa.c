/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:13:04 by msisto            #+#    #+#             */
/*   Updated: 2024/01/25 09:55:15 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	size(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	if (num < 0)
		len++;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		len;

	len = size(n);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	out[len] = '\0';
	if (n < 0)
		out[0] = '-';
	else if (n < 10 && n >= 0)
	{
		out[0] = n + 48;
		return (out);
	}
	while (len-- > 0 && n)
	{
		if (n < 0)
			out[len] = (-(n % 10)) + 48;
		else
			out[len] = (n % 10) + 48;
		n /= 10;
	}
	return (out);
}
