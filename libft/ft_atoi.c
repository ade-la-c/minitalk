/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:33:02 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/15 16:54:13 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkisspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	size_t		i;
	size_t		res;
	int			neg;

	i = 0;
	res = 0;
	neg = 1;
	while (checkisspace(s[i]) == 1)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		res = res * 10 + (s[i++] - 48);
	if (res > INT32_MAX)
		return (-1);
	return (res * neg);
}
