/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_ALTERNATIVE.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:56:30 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/22 14:44:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS1(nb) (nb < 0 ? -(nb) : nb)

# define ABS2(nb) do{\
	if (nb < 0)\
		nb = (-nb);\
	}while(0)


// BELOW DOES NOT WORK TO RETURN STUFF

# define ABS3(nb) do{\
        if (nb < 0)\
                -nb;\
	else\
		nb;\
        }while(0)

#endif /*FT_ABS_H*/


#include <stdio.h>
int	main(void)
{
	int nb = -5;

	ABS2(nb);
	printf("==%d==\n", nb);
	if (ABS1(nb) < 6)	
		printf("==%d==\n", nb);
	printf("\n");	
	
	return 0;
}
