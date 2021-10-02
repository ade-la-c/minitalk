/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:31:23 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/10/02 18:01:12 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/*

void	signbr_base(long long num, int base_len, char *base, int pid)
{
	char	bool;

	if (num >= base_len)
		signbr_base(num / base_len, base_len, base, pid);
	bool = base[num % base_len];
	if (bool == '0')
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
	else if (bool == '1')
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

// */

static void	send_char(int c, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		c = c << 1;
		if ((c & (1 << 8)) == 0)
		{
			if (kill(pid, SIGUSR1))
				exit_error("wrong pid");
			usleep(200);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_error("wrong pid");
			usleep(200);
		}
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;
	int		i;

	if (ac != 3)
		return (0);
	pid = (pid_t)ft_atoi(av[1]);
	str = av[2];
	i = 0;
	while (str[i])
		send_char((int)str[i++], pid);
	return (0);
}
