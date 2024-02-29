/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:46:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/12 09:59:31 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*loop;

	loop = str;
	while (*loop != '\0')
	{
		if (*loop >= 'a' && *loop <= 'z')
			*loop = *loop - 32;
		loop++;
	}
	return (str);
}
/*
int     main(void)
{
	char str1[] ="qrNout";
        char str2[] = "fad543fer";

	ft_strupcase(str1);
	ft_strupcase(str2);
        printf("string: \"%s\"\n", str1);
        printf("string: \"%s\"\n", str2);

        return (0);
}
*/
