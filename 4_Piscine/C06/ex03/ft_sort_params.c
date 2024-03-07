/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:14:11 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/19 09:39:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_str_cmp(char *s1, char *s2)
{
	while (*s1 == *s2 && s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putargv(char **s, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		ft_putstr(s[i]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	char	*tmp;

	n = 1;
	while (n < argc)
	{
		i = 2;
		while (i < argc)
		{
			if (ft_str_cmp(argv[i - 1], argv[i]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i - 1];
				argv[i - 1] = tmp;
			}
			i++;
		}
		n++;
	}
	ft_putargv(argv, argc);
	return (0);
}
