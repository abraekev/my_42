/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/09 13:03:26 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*loop;

	loop = dest;
	while (*src != '\0')
	{
		*loop = *src;
		src++;
		loop++;
	}
	*loop = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *src;
	char dest[20];
	
	src = "Arnout";
	printf("strcpy:\t\t%s\n", strcpy(dest,src));
	printf("ft_strcpy:\t%s\n", ft_strcpy(dest,src));
	printf("dest:\t%s\n", dest);
	printf("src:\t%s\n", src);
	return (0);
}
*/
