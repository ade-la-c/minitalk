/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:21:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/10/04 19:23:04 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

volatile sig_atomic_t	g_binary[2] = {-1, -1};

static void	sigusr1_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;//write(1, "0", 1);
	(void)context;
	(void)info;
	g_binary[0] = 0;
	g_binary[1] = info->si_pid;
	//usleep(100);
	if (kill(info->si_pid, SIGUSR1))
		exit_error("wrong pid");
}

static void	sigusr2_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;//write(1, "1", 1);
	(void)context;
	(void)info;
	g_binary[0] = 1;
	g_binary[1] = info->si_pid;
	//usleep(100);
	if (kill(info->si_pid, SIGUSR1))
		exit_error("wrong pid");
}

// /*

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					i;
	char				buf;

	sa1.__sigaction_u.__sa_sigaction = &sigusr1_handler;
	sa2.__sigaction_u.__sa_sigaction = &sigusr2_handler;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	i = 8;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar('\n');
	while (1)
	{
		g_binary[0] = -1;
		if (i > 0 && pause() == -1)
		{
			if (g_binary[0] == 1)
				buf += (1 << (i - 1));
			i--;
		}
		if (i == 0) 
		{
			i = 8;
			//write(1, " ", 1);
			if (buf)
				write(1, &buf, 1);
			else
			{
				write(1, "\n", 1);
				if (kill(g_binary[1], SIGUSR2) == -1)
					exit_error("wrong pid");
			}
			buf = 0;
		}
	}
	return (0);
}

// */
