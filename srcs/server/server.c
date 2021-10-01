/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:21:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/10/01 19:06:42 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

volatile sig_atomic_t	g_binary = -1;

char	*joinchar(char *str, char c)
{
	int		i;
	char	*s;

	i = 0;
	free(str);
	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!s)
		exit_error("malloc failed");
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (s);
}

static void	sigusr1_handler(int sig)
{
	(void)sig;
	g_binary = 0;
}

static void	sigusr2_handler(int sig)
{
	(void)sig;
	g_binary = 1;
}

// /*

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					i;
	char				buf;
	char				*str;

	sa1.__sigaction_u.__sa_handler = &sigusr1_handler;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.__sigaction_u.__sa_handler = &sigusr2_handler;
	sigaction(SIGUSR2, &sa2, NULL);
	i = 0;
	str = NULL;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar('\n');
	while (1)
	{
		pause();
		if (i <= 7)
		{
			buf = buf << 1;
			buf += g_binary;
			i++;
		}
		if (i == 7)
		{
			i = 0;
			write(1, &buf, 1);
			buf = 0;
		}
		// printf("poup\n");
		g_binary = -1;
	}
	return (0);
}

// */
