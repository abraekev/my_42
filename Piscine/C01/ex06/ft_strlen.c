/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:39:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/09 10:29:51 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		str++;
		n++;
	}
	return (n);
}
/*
int main(void)
{
    char *str;

    str = "Hello World!";
    printf("de lengte van de string is: %d\n",ft_strlen(str));
    return 0;
}
*/
