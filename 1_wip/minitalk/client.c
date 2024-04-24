/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:29:30 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/24 14:55:27 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>



void	send_string(int pid, char *s, size_t len)
{
	int	i;

	if (!s)
		return ((void)ft_printf("No string to be sent.\n"));
	while(s)
	{
		i = -1;
		while (++i < 7)
		{
			/*	send over bits of *s	*/
			usleep(250);
		}
		s++;
	}
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
}
