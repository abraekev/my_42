/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 08:57:24 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/09 10:29:02 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	teller;
	int	noemer;

	teller = *a;
	noemer = *b;
	*a = teller / noemer;
	*b = teller % noemer;
}
/*
int main(void)
{
    int teller = 7;
    int noemer = 3;
    int *ptr_t = &teller;
    int *ptr_n = &noemer;
	printf("teller %d noemer %d \n", teller, noemer);    
    ft_ultimate_div_mod(ptr_t, ptr_n);
        printf("quotient %d rest %d \n", teller, noemer);
    return 0;
}
*/
