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

int	main(int argc, char **argv)
{
	const char	*str;
	t_flags		flags = {0};
	char		*fspec = "+#-0 40603.9090909c";

	int 		a = 10;
	void		*ptr = &a;
	
	//testing
	ft_printf("ft_printfs: =%s=\n", "DEZESTRING");
	ft_printf("ft_printfc: =%c=\n", '@');
	ft_printf("ft_printfi: =%i=\n", 0);
	ft_printf("ft_printfd: =%d=\n", INT_MIN);
	ft_printf("ft_printfu: =%u=\n", (unsigned int)INT_MAX);
	ft_printf("ft_printfx: =%x=\n", (unsigned int)INT_MAX-2345);
	ft_printf("ft_printfX: =%X=\n", (unsigned int)INT_MAX-2345);
	ft_printf("ft_printfp: =%p=\n", ptr);
	ft_printf("ft_printf: =%s= =%c= =%i= =%d= =%X=%%\n", "DEZESTRING", '@', 0, INT_MIN, 99, ptr);
	return (0);
}
