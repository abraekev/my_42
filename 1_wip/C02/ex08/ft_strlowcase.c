/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:46:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/12 10:27:32 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*loop;

	loop = str;
	while (*loop != '\0')
	{
		if (*loop >= 'A' && *loop <= 'Z')
			*loop = *loop + 32;
		loop++;
	}
	return (str);
}
/*
int     main(void)
{
	char str1[] ="qrNout";
        char str2[] = "fad543FER";

	ft_strlowcase(str1);
	ft_strlowcase(str2);
        printf("string: \"%s\"\n", str1);
        printf("string: \"%s\"\n", str2);

        return (0);
}
*/
