/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:46:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 09:43:19 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_char_is_alpha_digit(char x)
{
	if (x >= 'a' && x <= 'z')
		return (1);
	else if (x >= 'A' && x <= 'Z')
		return (2);
	else if (x >= '0' && x <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*loop;

	loop = str;
	if (ft_char_is_alpha_digit(loop[0]) == 1)
		*loop = *loop - 32;
	loop++;
	while (*loop != '\0')
	{
		if (ft_char_is_alpha_digit(*(loop - 1)) == 0)
		{
			if (ft_char_is_alpha_digit(*loop) == 1)
				*loop = *loop - 32;
		}
		else if (ft_char_is_alpha_digit(*loop) == 2)
			*loop = *loop + 32;
		loop++;
	}
	return (str);
}
/*
int     main(void)
{
	char str1[] ="salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	ft_strcapitalize(str1);
	printf("string: \"%s\"\n", str1);

        return (0);
}
*/
