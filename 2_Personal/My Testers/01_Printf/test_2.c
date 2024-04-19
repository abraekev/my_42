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
#include "./srcs/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

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

void	print_entry(char *s1, char *s2)
{
	printf("\033[33m%-10s\033[0m\033[33m%s\033[0m\n", s1, s2);
}

void	test_ptr(void *s, char *ptr)
{
	int	y = 42;
	void	*x = (void *)(&y);
	int	a;
	int	b;
	
	print_entry("VPTR", ptr);
	to_file_lb();
	a = printf("%p%p%p-%p-%p",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%p%p%p-%p-%p",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}

void	test_hex(unsigned int s, char *ptr)
{
	unsigned int	x = 42;
	int	a;
	int	b;
	
	print_entry("HEX", ptr);
	to_file_lb();
	a = printf("%x%x%x-%x-%x",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%x%x%x-%x-%x",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}

void	test_uint(unsigned int s, char *ptr)
{
	unsigned int	x = 42;
	int	a;
	int	b;
	
	print_entry("UINT", ptr);
	to_file_lb();
	a = printf("%u%u%u-%u-%u",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%u%u%u-%u-%u",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}

void	test_di(int s, char *ptr)
{
	int	x = 42;
	int	a;
	int	b;
	
	print_entry("DIGIT", ptr);
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
	
	print_entry("STR", ptr);
	to_file_lb();
	a = printf("%s%s%s-%s-%s",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%s%s%s-%s-%s",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}


void	test_c(char	s, char *ptr)
{
	char	x = 'x';
	int	a;
	int	b;
	
	print_entry("CHAR", ptr);
	to_file_lb();
	a = printf("%c%c%c-%c-%c",s,x,s,x,s);
	
	to_file_ft();
	b = ft_printf("%c%c%c-%c-%c",s,x,s,x,s);
	
	to_stdout();
	get_result(a, b);
}

void	test_percent(void)
{
	int	a;
	int	b;
	
	print_entry("PERCENT", "%%%");
	to_file_lb();
	a = printf("%%%%%%");
	
	to_file_ft();
	b = ft_printf("%%%%%%");
	
	to_stdout();
	get_result(a, b);
	
	//printf("(lb %d)\n", printf("%%%%%%"));
	//printf("(ft %d)\n", ft_printf("%%%%%%"));
}

/****************************************************************************/

void	testing(void)
{
	char	*lit = "string literal";
	char	strarr[] = "string array";
	char	*emptystr  = "\0";
	char	*nullstr = NULL;
	char	*escstr = "new\nline";	

//	CHAR TESTING
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

//	% TESTING
	ft_printf("\n");
	test_percent();


//	STR TESTING
	ft_printf("\n");
	test_s(lit, "str literal");
	test_s(strarr, "str array");
	test_s(emptystr, "empty str");
	test_s(escstr, "special char");
	test_s(nullstr, "NULL");
	test_s("\0\0\0\0", "mtp nulls");
	// both lb and ft give core dump
	//str_test('a', "char \'a\'");

//	D & I TESTING
	ft_printf("\n");
	test_di(INT_MIN, "INT_MIN");
	test_di(-987654321, "-987654321");
	test_di(0, "0");
	test_di(987654321, "987654321");
	test_di(INT_MAX, "INT_MAX");
	test_di(LONG_MAX - 10, "LONG_MAX - 10");
	test_di(LONG_MAX + 10, "LONG_MAX + 10");
	test_di(LONG_MIN - 10, "LONG_MIN - 10");
	test_di(LONG_MIN + 10, "LONG_MIN + 10");


//	U TESTING
	ft_printf("\n");
	test_uint(INT_MIN, "INT_MIN");
	test_uint(-987654321, "-987654321");
	test_uint(0, "0");
	test_uint(987654321, "987654321");
	test_uint(UINT_MAX, "UINT_MAX");
	test_uint(ULONG_MAX - 10, "ULONG_MAX - 10");
	test_uint(ULONG_MAX + 10, "ULONG_MAX + 10");
	test_uint(LONG_MIN - 10, "LONG_MIN - 10");
	test_uint(LONG_MIN + 10, "LONG_MIN + 10");

//	X TESTING
	ft_printf("\n");
	test_hex(INT_MIN, "INT_MIN");
	test_hex(-987654321, "-987654321");
	test_hex(0, "0");
	test_hex(987654321, "9897654321");
	test_hex(UINT_MAX, "UINT_MAX");
	test_hex(ULONG_MAX - 10, "ULONG_MAX - 10");
	test_hex(ULONG_MAX + 10, "ULONG_MAX + 10");
	test_hex(LONG_MIN - 10, "LONG_MIN - 10");
	test_hex(LONG_MIN + 10, "LONG_MIN + 10");


//	P TESTING
	ft_printf("\n");
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
	test_ptr((void *)(arr + 89), "ARR+89 out of bound");
	
	// function pointer
	test_ptr((void *)ft_printf, "Function PTR");
	
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
}

