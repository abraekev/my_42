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

void	test_ptr_x(void *x, void *y, char * ptr)
{
	ft_printf("\nPTR\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%p%p%pXX%p<<\n", x,x,y,y));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%p%p%pXX%p<<\n", x,x,y,y));
}

void	test_ptr(void *d, char *ptr)
{
	ft_printf("\nPTR\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%p<<\n", d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%p<<\n", d));
}

void	test_hex_x(unsigned int d, char *ptr)
{
	ft_printf("\nHEX\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%x%x%xXX%x<<\n", d,d,d,d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%x%x%xXX%x<<\n", d,d,d,d));
}

void	test_hex(unsigned int d, char *ptr)
{
	ft_printf("\nHEX\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%x<<\n", d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%x<<\n", d));
}

void	test_uint_x(unsigned int d, char *ptr)
{
	ft_printf("\nMULTI\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%u%u%uXX%u<<\n", d,d,d,d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%u%u%uXX%u<<\n", d,d,d,d));
}

void	test_uint(unsigned int d, char *ptr)
{
	ft_printf("\nUINT\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%u<<\n", d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%u<<\n", d));
}

void	digit_x(int d, char *ptr)
{
	ft_printf("\nMULTI\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%d%d%dXX%d<<\n", d,d,d,d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%d%d%dXX%d<<\n", d,d,d,d));
}

void	digit(int d, char *ptr)
{
	ft_printf("\nINT\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%d<<\n", d));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%d<<\n", d));
}

void	percent(void)
{
	ft_printf("\n");
	printf("lb: %d\n", printf("lb\t>>%%<<\n"));
	ft_printf("ft: %d\n", ft_printf("ft\t>>%%<<\n"));
}

void	char_test(char c, char *ptr)
{
	ft_printf("\nCHAR\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%c<<\n", c));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%c<<\n", c));
}

void	str_test(char	*s, char *ptr)
{
	ft_printf("\nSTR\t%s\n", ptr);
	printf("lb\t%d\n", printf("lb\t>>%s<<\n", s));
	ft_printf("ft\t%d\n", ft_printf("ft\t>>%s<<\n", s));
}


void	printline(char *s)
{
	if (s)
		ft_printf("=========%s=========\n", s);
	else
		ft_printf("=============================\n\n");
}
/****************************************************************************/

void	testing(void)
{
	char	*lit = "string literal";
	char	strarr[] = "string array";
	char	*emptystr  = "\0";
	char	*nullstr = NULL;
	char	*escstr = "new\nline";	


//	% TESTING
	printline("PERCENT");
	percent();
	printline(0);

//	CHAR TESTING
	printline("CHAR");
	char_test('A',"A");
	char_test(65, "65");
	char_test(-65, "-65");
	char_test('\n', "\\n");
	char_test('\t', "\\t");
	char_test('\0', "\\0");
	char_test('$', "$");
	char_test(455, "455");
	char_test(-322, "-322");
	char_test(L'€', "L\'€\'");
	char_test("hello", "hello");
	printline(0);

//	STR TESTING
	printline("STR");
	str_test(lit, "str literal");
	str_test(strarr, "str array");
	str_test(emptystr, "empty str");
	str_test(escstr, "special char");
	str_test(nullstr, "NULL");
	// both lb and ft give core dump
	//str_test('a', "char \'a\'");
	printline(0);

//	D & I TESTING
	printline("INT (D AND I)");
	digit(INT_MIN, "INT_MIN");
	digit(-987654321, "-987654321");
	digit(0, "0");
	digit(987654321, "987654321");
	digit(INT_MAX, "INT_MAX");
	digit(LONG_MAX - 10, "LONG_MAX - 10");
	digit(LONG_MAX + 10, "LONG_MAX + 10");
	digit(LONG_MIN - 10, "LONG_MIN - 10");
	digit(LONG_MIN + 10, "LONG_MIN + 10");
	digit_x(1234, "1234");
	printline(0);

//	U TESTING
	printline("UINT");
	test_uint(INT_MIN, "INT_MIN");
	test_uint(-987654321, "-987654321");
	test_uint(0, "0");
	test_uint(987654321, "987654321");
	test_uint(UINT_MAX, "UINT_MAX");
	test_uint(ULONG_MAX - 10, "ULONG_MAX - 10");
	test_uint(ULONG_MAX + 10, "ULONG_MAX + 10");
	test_uint(LONG_MIN - 10, "LONG_MIN - 10");
	test_uint(LONG_MIN + 10, "LONG_MIN + 10");
	test_uint_x(1234, "1234");
	printline(0);

//	X TESTING
	printline("HEX");
	test_hex(INT_MIN, "INT_MIN");
	test_hex(-987654321, "-987654321");
	test_hex(0, "0");
	test_hex(987654321, "9897654321");
	test_hex(UINT_MAX, "UINT_MAX");
	test_hex(ULONG_MAX - 10, "ULONG_MAX - 10");
	test_hex(ULONG_MAX + 10, "ULONG_MAX + 10");
	test_hex(LONG_MIN - 10, "LONG_MIN - 10");
	test_hex(LONG_MIN + 10, "LONG_MIN + 10");
	test_hex_x(1234, "1234");
	printline(0);

//	P TESTING
	printline("PTR");	
	// NULL
	test_ptr(NULL, "NULL");
	
	// basic
	int	x = 10;
	test_ptr((void *)&x, "PTR");
	
	// array
	int	arr[5];
	test_ptr((void *)&arr[2], "ARR[2]");
	test_ptr((void *)arr, "ARR");
	test_ptr((void *)(arr + 3), "ARR+3");
	test_ptr((void *)(arr + 89), "ARR+89");
	
	// function pointer
	test_ptr((void *)ft_printf, "F PTR");
	
	// struct pointer
	t_data d;
	test_ptr((void *)&d, "STR PTR");
	
	// double pointer
	int	*p = &x;
	int	**pp = &p;
	test_ptr((void *)pp, "**PTR");
	
	// mallocd pointer
	void *mem = malloc(5);
	test_ptr(mem, "MALLOC");
	
	// multiple pointers
	int	y = 56;
	test_ptr_x((void *)&x, (void *)&y, "2xPTR");
	printline(0);

}

