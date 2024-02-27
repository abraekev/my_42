/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 11:35:42 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_errno(int i)
{
	if (i < 0)
		i = errno;
	ft_putstr_fd(strerror(i), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_error(char	*s)
{
	ft_putstr_fd(s, STDERR_FILENO);
}

void	ft_big_error(char *s)
{
	ft_error(s);
	ft_error(": strerror: ");
	ft_errno(-1);
}
