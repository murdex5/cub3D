/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:40:22 by msisto            #+#    #+#             */
/*   Updated: 2024/01/25 12:05:39 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exclude(char s)
{
	if (s == ' ' || s == '\t' || s == '\n'
		|| s == '\r' || s == '\f' || s == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long int	num;
	int			seg;

	seg = 0;
	num = 0;
	while (exclude(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			seg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num * 10 < 0)
			return (-1);
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (seg == 1)
		num = -num;
	return (num);
}
