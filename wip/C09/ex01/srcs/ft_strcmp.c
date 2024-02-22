/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:06 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 09:38:08 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str1 = "apple";
	char	*str2 = "apply";
	char	*str3 = "";

	printf("ft_strcmp: %d\n",ft_strcmp(str1, str2));
	printf("strcmp: %d\n",strcmp(str1, str2));
	printf("ft_strcmp: %d\n",ft_strcmp("", ""));
	printf("ft_strcmp: %d\n",ft_strcmp(str1, str3));
        printf("strcmp: %d\n",strcmp("", ""));
        printf("strcmp: %d\n",strcmp(str1, str3));

	return (0);
}
*/
