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

void	testing(void);

void	to_file_ft()
{
	freopen("ft_output.txt", "w+", stdout);
}

void	to_file_lb()
{
	freopen("lb_output.txt", "w+", stdout);
}

void	to_stdout()
{
	freopen("/dev/tty", "w", stdout);
}

int	compare()
{
	char	bff_ft[1024];
	char	bff_lb[1024];
	int	i = -1;

	int fd_ft = open("./ft_output.txt", O_RDWR);
	int fd_lb = open("./lb_output.txt", O_RDWR);

	while (++i < 1024)
	{
		bff_ft[i] = 0;
		bff_lb[i] = 0;
	}
	read(fd_ft, bff_ft, 1023);
	read(fd_lb, bff_lb, 1023);
	close(fd_ft);
	close(fd_lb);

	if (ft_strncmp(bff_ft, bff_lb, 1024) == 0)
		return (1);
	return (0);
}

int	main()
{
	printf("(%d)LB\n", printf("1X%.03sYY", NULL));
	printf("(%d)LB\n", printf("2X%.9sYY", NULL));
	printf("(%d)LB\n", printf("3X%3sYY", NULL));
	printf("(%d)LB\n", printf("4X%9sYY", NULL));
	printf("(%d)LB\n", printf("5X%.-12sYY", NULL));
	printf("(%d)LB\n", ft_printf("6X%.-12sYY", NULL));
	printf("(%d)LB\n", printf("7X%.12sYY", NULL));
		
	//printf("mm%cmm%cmm\n\0XXXX%cXXXX", 76, 76, 76);
	//printf(" %c %c %c ", '0', 0, '1');


	//testing();
	return 0;
}
