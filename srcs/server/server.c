/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:21:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/10/02 18:19:21 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

volatile sig_atomic_t	g_binary = -1;

static void	sigusr1_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;//write(1, "0", 1);
	(void)context;
	ft_putnbr_fd(info->si_pid, 1);
	g_binary = 0;
}

static void	sigusr2_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;//write(1, "1", 1);
	(void)context;
	ft_putnbr_fd(info->si_pid, 1);
	g_binary = 1;
}

// /*

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					i;
	char				buf;

	sa1.__sigaction_u.__sa_sigaction = &sigusr1_handler;
	sa1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.__sigaction_u.__sa_sigaction = &sigusr2_handler;
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa2, NULL);
	i = 9;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar('\n');
	while (1)
	{
		while (--i > 0 && pause() == -1)
			if (g_binary == 1)
				buf += (1 << (i - 1));
		// if (i == 0)
		// {
			i = 9;			//	write(1, " ", 1);
			write(1, &buf, 1);//	write(1, "\n", 1);
			buf = 0;
		// }
		g_binary = -1;
	}
	return (0);
}

// */
