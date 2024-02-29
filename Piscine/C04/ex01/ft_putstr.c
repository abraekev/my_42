/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:22:25 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 12:31:30 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Create a function
//	that displays a string of characters on the standard output.

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write (1, str, 1);
		str++;
	}
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "";
	char	*str2 = "abc1";

	ft_putstr(str1);
	write(1,"\n",1);
	ft_putstr(str2);
	return(0);
}
*/
