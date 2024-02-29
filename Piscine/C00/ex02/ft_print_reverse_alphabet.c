/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:42:09 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/08 16:52:12 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	x;

	x = 'z';
	while (x >= 'a' )
	{
		write(1, &x, 1);
		x--;
	}
}

/*
int     main(void)
{
	ft_print_reverse_alphabet();
        return (0);
}
*/
