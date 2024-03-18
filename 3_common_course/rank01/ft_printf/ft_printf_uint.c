/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                          :+:      :+:    :+:   */
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
	int	count;
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

int	ft_printf_void_ptr(uintptr_t nbr)
{
	return (0);
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
	printf("\n=%d=\n", ft_printf_uint_base(677629, 'x'));

	return 0;
}
*/
