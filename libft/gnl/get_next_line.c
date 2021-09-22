/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:22:58 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/16 11:42:38 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	scan_gnl(char *s)
{
	int	pos;

	pos = 0;
	while (s && s[pos])
	{
		if (s[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

static char	*strjoin_eol(char *s, char *buf)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	while (buf && buf[j] && buf[j] != '\n')
		j++;
	tab = malloc(i + j + 1);
	i = 0;
	j = 0;
	while (s && s[i] && s[i] != '\n')
		tab[j++] = s[i++];
	while (buf && *buf && *buf != '\n')
		tab[j++] = *buf++;
	tab[j] = 0;
	free(s);
	return (tab);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFERSIZE + 1];
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	*line = strjoin_eol(NULL, buf);
	if (!line || !*line)
		return (-1);
	while (scan_gnl(buf) == -1 && ret && ret != -1)
	{
		ret = read(fd, buf, BUFFERSIZE);
		buf[ret] = 0;
		*line = strjoin_eol(*line, buf);
	}
	if (!buf[0])
		return (0);
	ret = scan_gnl(buf) + 1;
	while (buf[ret] && buf[i])
		buf[i++] = buf[ret++];
	buf[i] = 0;
	return (1);
}
