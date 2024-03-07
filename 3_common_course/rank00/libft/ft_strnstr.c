/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:13 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 10:28:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find == 0)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i + j] && i + j < len)
			j++;
		if (to_find[j] == 0)
			return (((char *)str) + i);
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*berg = "Hello Woxx World!";
	char	*berg2 = "123456";
	char	*naald = "56";

	printf("berg: %s\n", berg);
	char *x = ft_strnstr(berg, naald, 3);
	
	printf("berg: %s\tnaald: %s\tresult: %s\n",berg, naald, x);
	printf("berg: %s\n", berg);

	x = ft_strnstr(berg2, naald, 20);
    printf("berg: %s\tnaald: %s\tresult: %s\n",berg2, naald, x);
       

	return (0);
}
*/
