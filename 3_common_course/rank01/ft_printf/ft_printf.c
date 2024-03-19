/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	choose_print(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_char((char)va_arg(args, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_printf_sint(va_arg(args, signed int)));
	if (c == 'p')
		return (ft_printf_void_ptr(va_arg(args, uintptr_t), 1));
	if (c == 'u' || c == 'x' || c == 'X')
		return (ft_printf_uint_base(va_arg(args, unsigned int), c));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	count;
	va_list	args;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s != '%')
			ft_putchar_fd(*s, 1);
		else
		{
			if (*(s + 1) == '%')
				ft_putchar_fd('%', 1);
			else
				count += choose_print(*(s + 1), args) - 1;
			s++;
		}
		count++;
		s++;
	}
	return (count);
}
