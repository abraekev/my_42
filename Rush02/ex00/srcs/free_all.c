/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-roec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:15:07 by bde-roec          #+#    #+#             */
/*   Updated: 2024/02/25 16:17:11 by bde-roec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	free_all(int *nb_array, char **dict_array, char *out)
{
	int	i;

	i = 0;
	while (dict_array[i] != 0)
	{
		free(dict_array[i]);
		i++;
	}
	free(nb_array);
	free(dict_array);
	free(out);
}
