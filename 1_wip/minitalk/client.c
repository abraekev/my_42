/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:29:30 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/26 15:00:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (!bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(1000);
	}
}

void	send_string(int pid, char *s, size_t len)
{
	if (!s)
		return ((void)ft_printf("No string to be sent.\n"));
	while(*s)
	{
		send_char(pid, *s);
		s++;
		usleep(1000);
	}
	send_char(pid, 0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error. Check your arguments.\n"), 0);                
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("bad pid\n"), 0);
	str = argv[2];
	send_string(pid, str, ft_strlen(str));
	return (0);
}
