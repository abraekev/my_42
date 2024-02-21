/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 08:34:33 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/09 10:28:37 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
    int teller = 7;
    int noemer = 3;
    int quotient;
    int rest;
    int *ptr1 = &quotient;
    int *ptr2 = &rest;

    ft_div_mod(teller, noemer, ptr1, ptr2);
    printf("The value of quotient is: %d\n", quotient);
    printf("The value of mod is: %d\n", rest);

    return 0;
}
*/
