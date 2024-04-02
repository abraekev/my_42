/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	testing(void)
{
	// %
	printf("\nl%%\n");
	ft_printf("f%%\n");

	// Character
	printf("\nCharacter: %c\n", 'A');
    	ft_printf("Character: %c\n", 'A');
	
    	// String
    	printf("\nString: %s\n", "Hello, World!");
    	ft_printf("String: %s\n", "Hello, World!");

    	// Integer
    	printf("\nInteger: %d\n", 123);
    	ft_printf("Integer: %d\n", 123);

    	// Integer with field width
    	printf("\nInteger with field width: %10d\n", 123);
    	ft_printf("Integer with field width: %10d\n", 123);

    	// Integer with left justification
    	printf("\nLeft Justified: %-10dEnd\n", 123);
    	ft_printf("Left Justified: %-10dEnd\n", 123);

    	// Unsigned integer
    	printf("\nUnsigned: %u\n", 150);
    	ft_printf("Unsigned: %u\n", 150);

    	// Hexadecimal (lowercase)
    	printf("\nHex (lowercase): %x\n", 255);
    	ft_printf("Hex (lowercase): %x\n", 255);

    	// Hexadecimal (uppercase)
    	printf("\nHex (uppercase): %X\n", 255);
    	ft_printf("Hex (uppercase): %X\n", 255);

    	// Hexadecimal with # flag
    	printf("\nHex with #: %#x\n", 255);
    	ft_printf("Hex with #: %#x\n", 255);

    	// Percent sign
    	printf("\nPercent sign: %%\n");
    	ft_printf("Percent sign: %%\n");

    	// Integer with zero padding
    	printf("\nZero padding: %010d\n", 123);
    	ft_printf("Zero padding: %010d\n", 123);

   	// Integer with + flag
    	printf("\nPlus flag: %+d\n", 123);
    	ft_printf("Plus flag: %+d\n", 123);

    	// Integer with space flag
    	printf("\nSpace flag: % d\n", 123);
    	ft_printf("Space flag: % d\n", 123);

    	// Integer with precision
    	printf("\nPrecision: %.5d\n", 123);
    	ft_printf("Precision: %.5d\n", 123);

    	// Integer with field width, left justification, and precision
    	printf("\nWidth, left justify, precision: %-10.5d\n", 123);
    	ft_printf("Width, left justify, precision: %-10.5d\n", 123);
    	//
}

