/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:45 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error(void)
{
	ft_putstr(strerror(errno));
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		error();
		return (0);
	}
	
	return (0);
}
