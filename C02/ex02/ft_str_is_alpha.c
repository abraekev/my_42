/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:00:48 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 11:52:19 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that returns 1 if the string given as a parameter contains only
alphabetical characters, and 0 if it contains any other character.

!! It should return 1 if str is empty.
*/

int	ft_str_is_alpha(char *str)
{
	if (*str == 0)
		return (1);
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "abc";
	char	*str2 = "ABC";
        char    *str3 = "AbC";
	char	*str4 = "a2c";
	char	*str5 = "A2C";
	char	*str6 = "A2c";
	char 	*str7 = "";

	printf("string: \"%s\" is: %d\n",str1,ft_str_is_alpha(str1));
	printf("string: \"%s\" is: %d\n",str2,ft_str_is_alpha(str2));
        printf("string: \"%s\" is: %d\n",str3,ft_str_is_alpha(str3));
        printf("string: \"%s\" is: %d\n",str4,ft_str_is_alpha(str4));
        printf("string: \"%s\" is: %d\n",str5,ft_str_is_alpha(str5));
        printf("string: \"%s\" is: %d\n",str6,ft_str_is_alpha(str6));
        printf("string: \"%s\" is: %d\n",str7,ft_str_is_alpha(str7));
	
	return (0);
}
*/
