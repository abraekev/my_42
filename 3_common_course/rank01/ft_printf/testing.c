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

void	test_ptr_x(void *x, void *y)
{
	printf("lb: %d\n", printf("lb>>%p%p%pXX%p<<\n", x,x,y,y));
	ft_printf("ft: %d\n", ft_printf("ft>>%p%p%pXX%p<<\n", x,x,y,y));
	ft_printf("\n");
}

void	test_ptr(void *d)
{
	printf("lb: %d\n", printf("lb>>%p<<\n", d));
	ft_printf("ft: %d\n", ft_printf("ft>>%p<<\n", d));
	ft_printf("\n");
}

void	test_hex_x(unsigned int d)
{
	printf("lb: %d\n", printf("lb>>%x%x%xXX%x<<\n", d,d,d,d));
	ft_printf("ft: %d\n", ft_printf("ft>>%x%x%xXX%x<<\n", d,d,d,d));
	ft_printf("\n");
}

void	test_hex(unsigned int d)
{
	printf("lb: %d\n", printf("lb>>%x<<\n", d));
	ft_printf("ft: %d\n", ft_printf("ft>>%x<<\n", d));
	ft_printf("\n");
}

void	test_uint_x(unsigned int d)
{
	printf("lb: %d\n", printf("lb>>%u%u%uXX%u<<\n", d,d,d,d));
	ft_printf("ft: %d\n", ft_printf("ft>>%u%u%uXX%u<<\n", d,d,d,d));
	ft_printf("\n");
}

void	test_uint(unsigned int d)
{
	printf("lb: %d\n", printf("lb>>%u<<\n", d));
	ft_printf("ft: %d\n", ft_printf("ft>>%u<<\n", d));
	ft_printf("\n");
}

void	digit_x(int d)
{
	printf("lb: %d\n", printf("lb>>%d%d%dXX%d<<\n", d,d,d,d));
	ft_printf("ft: %d\n", ft_printf("ft>>%d%d%dXX%d<<\n", d,d,d,d));
	ft_printf("\n");
}

void	digit(int d)
{
	printf("lb: %d\n", printf("lb>>%d<<\n", d));
	ft_printf("ft: %d\n", ft_printf("ft>>%d<<\n", d));
	ft_printf("\n");
}

void	percent(void)
{
	printf("lb: %d\n", printf("lb>>%%<<\n"));
	ft_printf("ft: %d\n", ft_printf("ft>>%%<<\n"));
	ft_printf("\n");
}

void	char_test(char c)
{
	printf("lb: %d\n", printf("lb>>%c<<\n", c));
	ft_printf("ft: %d\n", ft_printf("ft>>%c<<\n", c));
	ft_printf("\n");
}

void	str_test(char	*s)
{
	printf("lb: %d\n", printf("lb==%s==\n", s));
	ft_printf("ft: %d\n", ft_printf("ft==%s==\n", s));
	ft_printf("\n");	
}

/****************************************************************************/

void	testing(void)
{
	char	*lit = "string literal";
	char	strarr[] = "string array";
	char	*emptystr  = "\0";
	char	*nullstr = NULL;
	char	*escstr = "new\nline";	

/*	
//	% TESTING
	percent();

//	CHAR TESTING

	char_test('A');
	char_test(65);
	char_test(-65);
	char_test('\n');
	char_test('\t');
	char_test('\0');
	char_test('$');
	char_test(455);
	char_test(-322);
	char_test(L'€');
	char_test("hello");
	
//	STR TESTING
	str_test(lit);
	str_test(strarr);
	str_test(emptystr);
	str_test(escstr);
	str_test(nullstr);

//	D TESTING
	digit(INT_MIN);
	digit(-987654321);
	digit(0);
	digit(987654321);
	digit(INT_MAX);
	digit(LONG_MAX - 10);
	digit(LONG_MAX + 10);
	digit(LONG_MIN - 10);
	digit(LONG_MIN + 10);
	digit_x(1234);

//	U TESTING
	test_uint(INT_MIN);
	test_uint(-987654321);
	test_uint(0);
	test_uint(987654321);
	test_uint(UINT_MAX);
	test_uint(ULONG_MAX - 10);
	test_uint(ULONG_MAX + 10);
	test_uint(LONG_MIN - 10);
	test_uint(LONG_MIN + 10);
	test_uint_x(1234);

//	X TESTING
	test_hex(INT_MIN);
	test_hex(-987654321);
	test_hex(0);
	test_hex(987654321);
	test_hex(UINT_MAX);
	test_hex(ULONG_MAX - 10);
	test_hex(ULONG_MAX + 10);
	test_hex(LONG_MIN - 10);
	test_hex(LONG_MIN + 10);
	test_hex_x(1234);
*/

//	P TESTING
	
	// NULL
	test_ptr(NULL);
	
	// basic
	int	x = 10;
	test_ptr((void *)&x);
	
	// array
	int	arr[5];
	test_ptr((void *)&arr[2]);
	test_ptr((void *)arr);
	test_ptr((void *)(arr + 3));
	test_ptr((void *)(arr + 89));
	
	// function pointer
	test_ptr((void *)ft_printf);
	
	// struct pointer
	t_data d;
	test_ptr((void *)&d);
	
	// double pointer
	int	*p = &x;
	int	**pp = &p;
	test_ptr((void *)pp);
	
	// mallocd pointer
	void *mem = malloc(5);
	test_ptr(mem);
	
	// multiple pointers
	int	y = 56;
	test_ptr_x((void *)&x, (void *)&y);
}

