/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:04:17 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/06/01 17:39:54 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	s2 = (malloc(sizeof(char) * size + 1));
	if (!s2)
		return (NULL);
	return (ft_strcpy(s2, s1));
}
