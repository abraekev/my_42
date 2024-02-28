/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 10:51:48 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_ult_putchar(char c, int out, int size)
{
	write(out, &c, size);
}

void	ft_ult_putstr(char *str, int out, int len)
{
	int	i;

	if (!len)
		len = ft_strlen(str);
	i = -1;
	while (++i < len)
		ft_ult_putchar(str[i], out, 1);
}

void	ft_errno(int i)
{
	if (i < 0)
		i = errno;
	ft_ult_putstr(strerror(i), STDERR_FILENO, 0);
}

void	ft_error(char	*s)
{
	ft_ult_putstr(s, STDERR_FILENO, 0);
}

void	ft_big_error(char *s)
{
	ft_error(s);
	ft_error(": strerror: ");
	ft_errno(-1);
}
