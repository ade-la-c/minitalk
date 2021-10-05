/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:31:23 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/10/05 18:21:20 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	sigusr1_handler(int sig)
{
	usleep(100);
	(void)sig;
}

static void	sigusr2_handler(int sig)
{
	usleep(100);
	(void)sig;
	exit(0);
}

static void	send_char(int c, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		c = c << 1;
		if ((c & (1 << 8)) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_error("wrong pid");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_error("wrong pid");
		}
		usleep(200);
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa1;
	struct sigaction	sa2;
	char				*str;
	int					i;

	sa1.__sigaction_u.__sa_handler = &sigusr1_handler;
	sa2.__sigaction_u.__sa_handler = &sigusr2_handler;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	if (ac != 3)
		return (0);
	pid = (pid_t)ft_atoi(av[1]);
	str = av[2];
	i = 0;
	while (str[i])
		send_char((int)str[i++], pid);
	send_char(0, pid);
	return (0);
}
