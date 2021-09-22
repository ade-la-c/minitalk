/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:42:11 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/27 14:13:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlgt(int n)
{
	int			count;

	count = 1;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9 && ++count)
		n /= 10;
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			lgt;

	nb = n;
	lgt = strlgt(nb);
	if (nb == INT_FAST32_MIN)
		return (ft_strdup("-2147483648"));
	str = ft_calloc((lgt + 1), 1);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	while (lgt > 0)
	{
		str[--lgt] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
