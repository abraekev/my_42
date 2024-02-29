/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:47:29 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/08 10:01:45 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int nb)
{
	char	answer;

	if (nb < 0)
	{
		answer = 'N';
	}
	else
	{
		answer = 'P';
	}
	write (1, &answer, 1);
}
/*
int	main(void)
{
	ft_is_negative(5);
	ft_is_negative(-5);
	ft_is_negative(0);
	return (0);
}
*/
