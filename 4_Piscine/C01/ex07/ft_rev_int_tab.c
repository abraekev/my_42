/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:49:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/09 10:45:45 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	tssnb;

	n = 0;
	while (n < (size / 2))
	{
		tssnb = *(tab + n);
		*(tab + n) = *(tab + (size - 1 - n));
		*(tab + (size - 1 - n)) = tssnb;
		n++;
	}
}

/*

int main(void)
{
    int arrayVanNummers[]={21, 42, 52636, -3654};
    int size;
    int *ptr_arr;

    size =4;
    ptr_arr = arrayVanNummers;

    for (int i = 0; i< size;i++)
    {
            printf("%d ", arrayVanNummers[i]);
    }

    ft_rev_int_tab(ptr_arr, size);

    for (int i = 0; i< size;i++)
    {
	    printf("%d ", arrayVanNummers[i]);
    }
    return 0;
}
*/
