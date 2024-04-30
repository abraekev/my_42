/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:23:12 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/30 11:40:54 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>

int	g_siginfo[2];

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	acknowledge(int endofstr)
{
	usleep(125);
	if (endofstr)
	{
		if (kill(g_siginfo[0], SIGUSR2) == -1)
			ft_exit("\nError. Signal was not sent.");
	}
	else
	{
		if (kill(g_siginfo[0], SIGUSR1) == -1)
			ft_exit("\nError. Signal was not sent.");
	}
}

void	process_bit(char *c)
{
	static int	i = 0;
	int			bit;

	if (g_siginfo[1] == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	if (i++ < 8)
		*c = (*c << 1) | bit;
	if (i == 8)
	{
		if (!*c)
			acknowledge(1);
		else
			write(1, c, 1);
		i = 0;
		*c = 0;
	}
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	g_siginfo[0] = info->si_pid;
	g_siginfo[1] = signal;
}

void	ini_sa(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	char	c;

	ini_sa();
	ft_printf("pid is: %d\n", getpid());
	c = 0;
	while (1)
	{
		pause();
		process_bit(&c);
		acknowledge(0);
	}
}
