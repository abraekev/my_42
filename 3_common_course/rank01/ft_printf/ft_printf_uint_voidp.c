/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint_voidp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_put_uint_base(unsigned int nbr, char *base, int b_len)
{
	int		count;
	char	c;

	count = 1;
	if (nbr >= b_len)
	{
		count += ft_put_uint_base(nbr / b_len, base, b_len);
	}
	c = *(base + (nbr % b_len));
	ft_putchar_fd(c, 1);
	return (count);
}

int	ft_printf_void_ptr(uintptr_t nbr, int is_addr)
{
	int		count;
	size_t	b_len;
	char	*base;
	char	c;

	count = 1;
	if (is_addr)
	{
		ft_putstr_fd("0x", 1);
		count += 2;
	}
	base = "0123456789abcdef";
	b_len = ft_strlen(base);
	if (nbr >= b_len)
		count += ft_printf_void_ptr(nbr / b_len, 0);
	c = *(base + (nbr % b_len));
	ft_putchar_fd(c, 1);
	return (count);
}

int	ft_printf_uint_base(unsigned int nbr, char c)
{
	char	*base;

	if (c == 'u')
		base = "0123456789";
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	return (ft_put_uint_base(nbr, base, ft_strlen(base)));
}

/****************************************************************************

int	main()
{
	int n = 10;
	void *p = &n;
	
	printf("\n%d\n", ft_printf_void_ptr((uintptr_t)(p), 1));
	return 0;
}
*/
