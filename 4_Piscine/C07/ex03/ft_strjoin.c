/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:53 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 13:42:28 by abraekev         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	char	*output;

	output = dest;
	while (*dest != '\0')
	{
		dest ++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (output);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strjoin_len(int size, char **strs, char *sep)
{
	int	i;
	int	size_out;

	i = -1;
	size_out = 0;
	while (++i < size)
	{
		size_out += ft_str_len(strs[i]);
		if (i < (size - 1))
			size_out += ft_str_len(sep);
	}
	return (size_out);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		size_out;
	int		i;

	if (size == 0)
	{
		out = malloc(1);
		return (out);
	}
	i = -1;
	size_out = ft_strjoin_len(size, strs, sep);
	out = malloc(size_out + 1);
	ft_strcpy(out, "");
	i = -1;
	while (++i < size)
	{
		out = ft_strcat(out, strs[i]);
		if ((i < size - 1))
			out = ft_strcat(out, sep);
	}
	return (out);
}
/*
#include <stdio.h>

int	main(void)
{
	char **strs = malloc(sizeof(char*) * 3);
	strs[0] = malloc(4);
	strs[1] = malloc(4);
	strs[2] = malloc(6);

	ft_strcpy(strs[0], "123");
	ft_strcpy(strs[1], "");
	ft_strcpy(strs[2], "789");


	char *str = ft_strjoin(3, strs, "**");
	printf("\n===%s===\n", str);
	return (0);
}
*/
