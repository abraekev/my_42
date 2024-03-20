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

	printf("=%s=\n", fspec);
	get_min_width(&flags, fspec);
	printf("=%d=\n", flags.min_width);
	str = "abc%%zyx";
	ft_printf(str);
	return (0);
}
