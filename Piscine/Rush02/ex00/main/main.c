/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:32:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/25 21:06:57 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush_02.h"

void	do_the_thing(char **dict_array, int *nb_array)
{
	char	*output;

	output = print_nb(nb_array, dict_array);
	if (!output || ft_strstr(output, "ERROR"))
		ft_putstr("Dict Error\n");
	else
		ft_putstr(output);
	free_all(nb_array, dict_array, output);
}

int	main(int argc, char **argv)
{
	char	*filepath;
	char	**dict_array;
	int		*nb_array;

	filepath = "./dicts/numbers.dict";
	if (argc > 3 || argc < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 3)
		filepath = argv[1];
	dict_array = create_dict_arr(filepath, 4096);
	if (!dict_array)
		return (0);
	if (check_numbers(argv[argc - 1]) == 0
		|| ft_atol_check(argv[argc - 1]) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	nb_array = ft_atol(argv[argc - 1]);
	if (nb_array && dict_array)
		do_the_thing(dict_array, nb_array);
	return (0);
}
