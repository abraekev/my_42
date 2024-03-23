/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 13:04:29 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	testing(void);

int	main(int argc, char **argv)
{
	const char	*str;
	t_flags		f 	= initiate_flags();
	char		*fspec 	= "+#-0 40603.9090909c";
	
	//ft_printf("%5%");
	//printf("\n");
	ft_printf("ft==%4532%==\n");
	printf("lb==%4532%==\n");
	
	//ft_printf("\n\n");
	//testing();
	return (0);
}
