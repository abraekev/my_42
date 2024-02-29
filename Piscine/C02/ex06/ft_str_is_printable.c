/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:46:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/12 09:00:47 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= ' ' && *str <= '~'))
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
