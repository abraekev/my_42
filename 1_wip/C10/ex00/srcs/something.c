/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:50:23 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/24 13:07:37 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		ft_putchar(*str);
		str++;
	}
}

void	error_msg(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
