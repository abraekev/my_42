/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:13 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 10:28:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
       The  strstr() function finds the first occurrence of the substring nee‐
       dle in the string haystack.  The terminating null bytes ('\0') are  not
       compared.

       These functions return a pointer to the beginning of the  located  sub‐
       string, or NULL if the substring is not found.
*/
char	*ft_strstr(char *str, char *to_find)
{
	char	*begin_to_find;
	int		teller;

	teller = 0;
	begin_to_find = to_find;
	while (*to_find != '\0' && *str != '\0')
	{
		if (*str == *to_find)
		{
			str++;
			to_find++;
			teller++;
		}
		else
		{
			str++;
			to_find = begin_to_find;
			teller = 0;
		}
	}
	if (*to_find == '\0')
		return (str - teller);
	else
		return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*berg = "Hello Woxx World!";
	char	*berg2 = "123456";
	char	*naald = "";

	printf("berg: %s\n", berg);
	char *x = ft_strstr(berg, naald);
	char *y = strstr(berg, naald);
	printf("berg: %s\tnaald: %s\tresult: %s\n",berg, naald, x);
	printf("berg: %s\tnaald: %s\tresult: %s\n",berg, naald, y);
	printf("berg: %s\n", berg);

	x = ft_strstr(berg2, naald);
        y = strstr(berg2, naald);
        printf("berg: %s\tnaald: %s\tresult: %s\n",berg2, naald, x);
        printf("berg: %s\tnaald: %s\tresult: %s\n",berg2, naald, y);


	return (0);
}
*/
