/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:06 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 09:51:26 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str1 = "applxxxx";
	char	*str2 = "appleooo";
	char	*str3 = "appleooo";
	char	*str4 = "appleo";

	printf("ft_strncmp: %d\n",ft_strncmp(str1, str2, 5));
	printf("ft_strncmp: %d\n",ft_strncmp(str3, str2, 5));
	printf("ft_strncmp: %d\n",ft_strncmp(str4, str2, 5));
	printf("ft_strncmp: %d\n",ft_strncmp("", str2, 5));

	printf("strncmp: %d\n",strncmp(str1, str2, 5));
	printf("strncmp: %d\n",strncmp(str3, str2, 5));
	printf("strncmp: %d\n",strncmp(str4, str2, 5));
	printf("strncmp: %d\n",strncmp("", str2, 5));

	return (0);
}
*/
