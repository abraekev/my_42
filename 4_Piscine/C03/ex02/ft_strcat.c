/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:06 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 10:04:42 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Reproduce the behavior of the function strcat (man strcat).

char	*ft_strcat(char *dest, char *src)
{
	char	*output;

	output = dest;
	while (*dest != '\0')
	{
		dest ++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
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
	char	destination[25] = "Hello, X";
	char	*source = "Y world!";
    
	printf("destination: %s\n", destination);
	printf("source: %s\n", source);
    
	printf("ft_strcat: %s\n", ft_strcat(destination, source));
	printf("strcat: %s\n", strcat(destination, source));
	printf("destination: %s\n", destination);


	return (0);

}
*/
