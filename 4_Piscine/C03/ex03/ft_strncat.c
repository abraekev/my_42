/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:06 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 10:16:07 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Reproduce the behavior of the function strncat (man strcat).

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	teller;
	char			*output;

	output = dest;
	teller = 0;
	while (*dest != '\0')
	{
		dest ++;
	}
	while (*src != '\0' && teller < nb)
	{
		*dest = *src;
		dest++;
		src++;
		teller ++;
	}
	*dest = '\0';
	return (output);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	destination[25] = "aaaX";
	char	*source = "";
	unsigned int nb = 4;

	ft_strncat(destination, source, nb);
    
	printf("Concatenated string: %s\n", destination);
	printf("strncat %s\n", strncat(destination, source,nb));
	return (0);
}
*/
