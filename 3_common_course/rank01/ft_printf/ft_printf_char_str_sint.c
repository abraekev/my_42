/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str_sint.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_sintlen(int nbr)
{
	int	len;

	len = 0;
	if (!nbr)
		return (1);
	if (nbr >= 0)
		nbr = -nbr;
	else
		len++;
	while (nbr != 0)
	{
		len ++;
		nbr /= 10;
	}
	return (len);
}

int	ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_str(char *s)
{
	int	len;

	len = (int)ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}

int	ft_printf_sint(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (ft_sintlen(nbr));
}

/****************************************************************************

int	main()
{
	printf("%d\n", ft_sintlen(INT_MIN));

	return 0;
}
*/
