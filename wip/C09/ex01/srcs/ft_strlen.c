/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:44:29 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 12:21:02 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 	Create a function that counts 
// 	and returns the number of characters in a string.

int	ft_strlen(char *str)
{
	int	teller;

	teller = 0;
	while (*str != 0)
	{
		str++;
		teller++;
	}
	return (teller);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*p1 = "abcdef";
	char    *p2 = "";

	printf("ft_\t\t%s:\t%d\n", p1, ft_strlen(p1));
	printf("ft_\t\t%s:\t%d\n", p2, ft_strlen(p2));
	printf("lib\t\t%s:\t%d\n", p1, ft_strlen(p1));
	printf("lib\t\t%s:\t%d\n", p2, ft_strlen(p2));
	return (0);
}
*/
