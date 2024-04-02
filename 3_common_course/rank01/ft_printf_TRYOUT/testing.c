/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/02 14:25:35 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	char_test(char c)
{
	printf("lb: %d\n", printf("lb before null term >>%c<< after null term\n", c));
	ft_printf("ft: %d\n", ft_printf("ft before null term >>%c<< after null term\n", c));
	ft_printf("\n");
}

void	str_test(char	*s)
{
	printf("lb: %d\n", printf("lb==%s==\n", s));
	ft_printf("ft: %d\n", ft_printf("ft==%s==\n", s));
	ft_printf("\n");	
}

void	testing(void)
{
	char	*lit = "string literal";
	char	strarr[] = "string array";
	char	*emptystr  = "\0";
	char	*nullstr = NULL;
	char	*escstr = "new\nline";	
	

//	CHAR TESTING

//	char_test('A');
//	char_test(65);
//	char_test(-65);
//	char_test('\n');
//	char_test('\t');
	char_test('\0');
//	char_test('$');
	//char_test(455);
	//char_test(-322);
//	char_test(L'€');
//	char_test("hello");
	
//	STR TESTING
//	str_test(lit);
//	str_test(strarr);
	str_test(emptystr);
//	str_test(escstr);
//	str_test(nullstr);

}

