/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 13:20:23 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	no_arg(char **argv)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno != 0)
		{
			ft_error(basename(argv[0]));
			ft_error(": stdin: ");
			ft_errno(-1);
			ft_error("\n");
		}
	}
}

void	arg_error(char **argv, int i)
{
	if (errno != 0)
	{
		ft_error(basename(argv[0]));
		ft_error(": cannot open \'");
		ft_error(argv[i]);
		ft_error("\' for reading: ");
		ft_error(strerror(2));
		ft_error("\n");
	}
}

void	ft_put_tailheader(char *s)
{
	ft_putstr("==> ");
	ft_putstr(s);
	ft_putstr(" <==\n");
}

void	arg_biggerthan_2(int argc, char **argv)
{
	int	i;	

	if (argc > 2)
	{
		if (!arg_valid_bytes(argv[2]))
		{
			invalid_byte(argv);
			return ;
		}
		if (argc == 3)
		{
			no_arg(argv);
			return ;
		}
		i = 2;
		while (++i < argc)
		{
			if (argc > 4)
				ft_put_tailheader(argv[i]);
			if (ft_tail(argv[i], arg_valid_bytes(argv[2])) == 0)
				arg_error(argv, i);
			if (argc > 4)
				ft_putstr("\n");
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		no_arg(argv);
		return (0);
	}
	if (argc == 2)
	{
		if (has_c_option(argv))
			only_c(argv);
		return (0);
	}
	arg_biggerthan_2(argc, argv);
	return (0);
}
