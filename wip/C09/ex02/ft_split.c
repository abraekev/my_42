/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:08:27 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/22 12:03:02 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Create a function that splits a string of character depending 
	on another string of characters.
• You’ll have to use each character from the string charset
	as a separator.
• The function returns an array where each box contains the address
	of a string wrapped between two separators. The last element
	of that array should equal to 0 to indicate the end of the array.
• There cannot be any empty strings in your array. Draw your
	conclusions accordingly.
• The string given as argument won’t be modifiable.
*/

#include <stdlib.h>
//#include "ft.h"
#include <stdio.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	ft_get_length_out(char *str, char *charset)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while(str[i])
	{
		if (!ft_is_charset(str[i], charset))
			length++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
	}
	return (length);
}

char	**ft_split_strs(char **out, int length, char *charset, int i)
{
}

char	**ft_split(char *str, char *charset)
{
	char		**out
	int			length;
	int			i;

	length = ft_get_length_out(str, charset) + 1;
	printf("=%s=%d=\n", str, length);
	out = malloc(sizeof(char*) * length);
	if (!out)
		return (NULL);
	ft_split_strs(out, length, charset, -1);
	out[length - 1] = 0;
		


	return (NULL);
}

/* ************************************************************************** */

int	main(void)
{
	char	*str1 = "aa!!";
	char	*str2 = "!!aa";
	char	*str3 = "!!";
	char	*str4 = "aa";
	char	*str5 = "!!aa!!bb!!cc!!";
	char	*str6 = "!a!";

	char	*strs[6] = {str1,str2,str3,str4,str5,str6};
	char	*charset = "!, ?.";
	
	int	i=-1;
	while (++i < 6)
	{
		ft_split(strs[i],charset);
	}
	return (0);
}
