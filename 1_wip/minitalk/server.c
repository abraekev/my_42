/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:23:12 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:29 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       pid_t getpid(void);

#include <sys/types.h>
#include <unistd.h>
#include "libft.h"
#include <signal.h>

void	sig_handler(int	signal)
{
	ft_printf("sig received (in handler fnction)\n");
}

int	main()
{
	if (argc != 1)
		return (ft_printf("Error. Check your arguments.\n"), 0);	
	pid_t pid = getpid();
	ft_printf("pid = %d\n", (int)pid);

	signal(SIGUSR1, sig_handler);
	
	int	i = 0;
	while (i <10)
	{
		ft_printf("program running and paused, waiting for sig (press CTRL-C)\n");
		pause();
		ft_printf("continueing MAIN\n");
		i++;
	}
	ft_printf("end");
}
