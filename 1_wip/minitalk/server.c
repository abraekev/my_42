/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:23:12 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/26 15:01:55 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>

#include "libft.h"

#include  <stdio.h>

int		BIT[2];

void	process_bit(char *c)
{
	static int	i = 0;
	int		bit;
	
	if (BIT[1] == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	if (i++ < 8)
		*c = (*c << 1) | bit;
	if (i == 8)
	{
		write(1, c, 1);
		i = 0;
		*c = 0;
	}
	usleep(10);
	kill(BIT[0], SIGUSR1);
}

void	sig_handler(int	signal, siginfo_t *info, void *context)
{
	(void)context;
	BIT[0] = info->si_pid;
	BIT[1] = signal;
}

int	main()
{
	struct sigaction	sa;
	char				c;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("pid is: %d\n", getpid());
	
	c = 0;
	while (1)
	{
		pause();
		process_bit(&c);
	}
}
