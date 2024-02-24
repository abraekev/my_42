/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:32:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/24 13:35:54 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		error_msg("File name missing.");
		return (0);
	}
	if (argc > 2)
	{
		error_msg("Too many arguments.");
		return (0);
	}
	display_file(argv[1]);
	return (0);
}
