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


void	sig_handler(int	signal)
{
	static int	i = 0;
	static int	c = 0;
	int			bit;
	
	bit = 1;
	if (signal == SIGUSR1)
		bit = 0;
	if (i++ < 8)
		c = (c << 1) | bit;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	cleanup()
{
	ft_printf("EOF reached.\n");
}

int	main()
{
	struct sigaction sa;
	int	c;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	ft_printf("pid is: %d\n", getpid());
	atexit(cleanup);
		
	while (1)
		pause();
}
