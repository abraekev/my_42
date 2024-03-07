/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:50:14 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/19 10:10:53 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlength(char *src)
{
	int	c;

	c = 0;
	while (*src != 0)
	{
		src++;
		c++;
	}
	return (c);
}

char	*ft_strdup(char *src)
{
	char	*out;
	int		count;

	count = ft_strlength(src);
	out = malloc(count + 1);
	if (!out)
		return (NULL);
	else
		return (ft_strcpy(out, src));
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*src = "hallo";
	char	*out = ft_strdup(src);
	char	*out2 = strdup(src);

	printf("%s\n", out);
	printf("%s\n", out2);

	free(out);
	free(out2);
	return (0);
}
*/
