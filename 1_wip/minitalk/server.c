/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:23:12 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/25 14:36:20 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>

#include "libft.h"

int BIT = -1;

void	sig_handler(int	signal)
{
	if(signal == SIGUSR1)
		BIT = 0;
	else if (signal == SIGUSR2)
		BIT = 1;
}

void	cleanup()
{
	ft_printf("EOF reached.\n");
}

int	mt_get_char()
{
	int	c;
	int	base;
	
	base = 128;
	c = 0;
	while (base != 0)
	{
		pause();
		c += BIT * base;
		base /= 2;
		if (BIT == -1)
			exit(0);
		BIT = -1;
	}
	ft_putchar_fd(c, 1);
	return (c);
}

int	main()
{
	struct sigaction sa;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	ft_printf("pid is: %d\n", getpid();
	atexit(cleanup);
		
	while (1)
	{
		pause();
		c = mt_get_char();
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
