/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_str_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:54:34 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 12:15:04 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush_02.h"

char	*value_dict_array(char	*dict)
{
	int		i;
	int		j;
	char	*value;

	value = malloc(ft_strlen(dict) + 1);
	if (!value)
		return (NULL);
	i = 0;
	j = 0;
	while (dict[i] != ':')
		i++;
	while (dict[++i] == ' ')
	{
	}
	while (dict[i] != 0)
	{
		value[j] = dict[i];
		i++;
		j++;
	}
	value[j] = 0;
	return (value);
}

char	*get_print(char *search, char **dict_array)
{
	int	i;

	i = 0;
	while (dict_array[i])
	{
		if (ft_strncmp(search, dict_array[i], ft_strlen(search)) == 0)
			return (value_dict_array(dict_array[i]));
		i++;
	}
	return (NULL);
}

void	print_operator(int i, int *a, char *str)
{
	if (i == 3 && !(a[2] == 0 && a[1] == 0 && a[0] == 0))
		ft_strcat(str, ",");
	if (i == 2 && !(a[1] == 0 && a[0] == 0))
		ft_strcat(str, ",");
	if (i == 1 && !(a[0] == 0))
		ft_strcat(str, ",");
}

char	*print_nb(int *nb_array, char **dict_array)
{
	char	*str;
	int		i;

	str = malloc(2000);
	if (!str)
		return ("ERROR");
	str[0] = 0;
	if (nb_array[0] == 0 && nb_array[1] == 0
		&& nb_array[2] == 0 && nb_array[3] == 0)
		return (ft_strcat(add_search(0, dict_array, str), "\n" ));
	i = 4;
	while (--i >= 0)
	{
		if (nb_array[i])
		{
			if (i < 3 && nb_array[i + 1])
				ft_strcat(str, " ");
			get_triplet(nb_array[i], dict_array, str);
			get_suffix(i, dict_array, str);
			print_operator(i, nb_array, str);
		}
	}
	if (!str)
		return (ft_strcat(str, "ERROR"));
	return (ft_strcat(str, "\n"));
}

char	*get_suffix(int i, char **dict_array, char *str)
{
	if (i == 3)
	{
		ft_strcat(str, " ");
		add_search(1000000000, dict_array, str);
	}
	else if (i == 2)
	{
		ft_strcat(str, " ");
		add_search(1000000, dict_array, str);
	}
	else if (i == 1)
	{
		ft_strcat(str, " ");
		add_search(1000, dict_array, str);
	}
	else if (i == 0)
		return (str);
	if (!str)
		return (ft_strcat(str, "ERROR"));
	return (str);
}
