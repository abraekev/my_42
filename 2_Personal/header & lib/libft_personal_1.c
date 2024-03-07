/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_personal_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_ult(char c, int fd, int size)
{
	if (!size)
		size = 1;
	write(fd, &c, size);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putstr_ult(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
