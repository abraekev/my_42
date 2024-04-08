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

void	to_file_ft();
void	to_file_lb();
void	to_stdout();
int	compare();

void	get_result(int a, int b)
{
	if (compare() && a == b)
		ft_printf("\033[32mTRUE\033[0m\n");
	else
		ft_printf("\033[31mFALSE\033[0m\n");	
}

void	printline(char *s)
{
	if (s)
		ft_printf("====================|\033[33m%s\033[0m\n", s);
	else
		ft_printf("==========================\n\n");
}

void	print_entry(char *s)
{
	ft_printf("%-20s|", s);
}

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

void	test_di(int s, char *ptr)
{
	int	x = 42;
	int	a;
	int	b;
	
	print_entry(ptr);
	to_file_lb();
	a = printf("%d%d%d-%d-%d",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%d%d%d-%d-%d",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}

void	test_s(char	*s, char *ptr)
{
	char	*x = "x";
	int	a;
	int	b;
	
	print_entry(ptr);
	to_file_lb();
	a = printf("%s%s%s-%s-%s",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%s%s%s-%s-%s",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}

void	test_c(char c, char *ptr)
{
	char	x = 'x';
	int	a;
	int	b;
	
	print_entry(ptr);
	to_file_lb();
	a = printf("%c%c%c-%c-%c",c,x,c,x,c);
	
	to_file_ft();
	b = ft_printf("%c%c%c-%c-%c",c,x,c,x,c);

	to_stdout();
	get_result(a, b);
}

void	test_percent(void)
{
	int	a;
	int	b;
	
	print_entry("%");
	
	to_file_lb();
	a = printf("%%%%%%");
	
	to_file_ft();
	b = ft_printf("%%%%%%");
	
	to_stdout();
	get_result(a, b);
}

/****************************************************************************/

void	testing(void)
{
	char	*lit = "string literal";
	char	strarr[] = "string array";
	char	*emptystr  = "\0";
	char	*nullstr = NULL;
	char	*escstr = "new\nline";	


	char c = 0;
	char x = 'x';
	
	
	close(1);
	int	fd = open("bigtest.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, 1);
	printf("(%d)", ft_printf("%c%c%c-%c-%c",c,x,c,x,c));
	
	
/*	
	printf("(%d)", printf("%c%c%c-%c-%c",c,x,c,x,c));
	printf("\n");
	printf("(%d)", ft_printf("%c%c%c-%c-%c",c,x,c,x,c));
	printf("\n");


//	% TESTING
	printline("PERCENT");
	test_percent();
	printline(NULL);

//	CHAR TESTING
	printline("CHAR");
	test_c('A',"A");
	test_c(72, "72");
	test_c(-72, "-72");
	test_c('\n', "\\n");
	test_c('\t', "\\t");
	test_c('\0', "\\0");
	test_c('$', "$");
	test_c(455, "455");
	test_c(-322, "-322");
	test_c(L'€', "L'EUR sign'");
	//char_test("hello", "hello");
	printline(NULL);

//	STR TESTING
	printline("STR");
	test_s(lit, "str literal");
	test_s(strarr, "str array");
	test_s(emptystr, "empty str");
	test_s(escstr, "special char");
	test_s(nullstr, "NULL");
	// both lb and ft give core dump
	//str_test('a', "char \'a\'");
	printline(0);

//	D & I TESTING
	printline("INT (D AND I)");
	test_di(INT_MIN, "INT_MIN");
	test_di(-987654321, "-987654321");
	test_di(0, "0");
	test_di(987654321, "987654321");
	test_di(INT_MAX, "INT_MAX");
	test_di(LONG_MAX - 10, "LONG_MAX - 10");
	test_di(LONG_MAX + 10, "LONG_MAX + 10");
	test_di(LONG_MIN - 10, "LONG_MIN - 10");
	test_di(LONG_MIN + 10, "LONG_MIN + 10");
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
*/
}

