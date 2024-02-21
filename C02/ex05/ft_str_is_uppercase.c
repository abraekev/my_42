/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:41:35 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/12 08:45:16 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that returns 1 if the string given as a parameter contains only
uppercase alphabetical characters, and 0 if it contains any other character.
*/
#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int     main(void)
{
        char    *str1 ="AbcD";
        char    *str2 = "QBCD";

        printf("string: \"%s\" is: %d\n",str1,ft_str_is_uppercase(str1));
        printf("string: \"%s\" is: %d\n",str2,ft_str_is_uppercase(str2));

        return (0);
}
*/
