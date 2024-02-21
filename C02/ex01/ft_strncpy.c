/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 14:16:15 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *src;
	char dest[25];
	
	src = "Hello World!";
	printf("strncpy:\t\t%s\n", strncpy(dest, src, 5));
	printf("ft_strncpy:\t\t%s\n", ft_strncpy(dest, src, 5));
	
        printf("strncpy:\t\t%s\n", strncpy(dest, src, 20));
        printf("ft_strncpy:\t\t%s\n", ft_strncpy(dest, src, 20));

	printf("\n");
	printf("dest %s\n", dest);
        printf("src %s\n", src);

	return (0);
}
*/
