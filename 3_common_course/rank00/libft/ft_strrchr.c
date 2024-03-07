/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 17:45:49 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*start;

	str = (char *)s;
	start = str;
	while (*str)
		str++;
	while (str >= start)
	{
		if (*str == c)
			return (str);
		str--;
	}
	return (NULL);
}
