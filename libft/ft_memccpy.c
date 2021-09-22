/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:53:37 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/06/01 15:54:08 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	ch;

	i = -1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	ch = (unsigned char)c;
	while (++i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == ch)
			return (&str1[i + 1]);
	}
	return (NULL);
}
