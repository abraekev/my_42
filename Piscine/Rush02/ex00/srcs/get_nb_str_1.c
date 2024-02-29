/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_str_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:54:34 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 12:12:53 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush_02.h"

char	*get_doublet_search_small(int nb, char *search)
{
	if (nb >= 10 && nb < 100)
	{
		search[0] = '0' + (nb / 10);
		search[1] = '0' + (nb % 10);
		search[2] = 0;
	}
	else
	{
		search[0] = '0' + nb;
		search[1] = 0;
	}
	return (search);
}

char	*get_doublet_search(int nb)
{
	char	*search;

	search = malloc(13);
	if (!search)
		return (NULL);
	search[0] = 0;
	if (nb == 1000000000)
		ft_strcpy(search, "1000000000");
	else if (nb == 1000000)
		ft_strcpy(search, "1000000");
	else if (nb == 1000)
		ft_strcpy(search, "1000");
	else if (nb == 100)
		ft_strcpy(search, "100");
	else if (nb < 100)
		search = get_doublet_search_small(nb, search);
	if (!search)
		return (NULL);
	return (search);
}

char	*add_search(int nb, char **dict_array, char *str)
{
	char	*search;
	char	*add;

	search = get_doublet_search(nb);
	add = get_print(search, dict_array);
	free(search);
	if (!add)
		return (ft_strcat(str, "ERROR"));
	ft_strcat(str, add);
	free(add);
	return (str);
}

char	*get_doublet_str(int nb, char **dict_array, char *str)
{
	nb = nb % 100;
	if (nb < 20)
		add_search(nb, dict_array, str);
	else
	{
		add_search(((nb / 10) * 10), dict_array, str);
		if (nb % 10 != 0)
		{
			ft_strcat(str, "-");
			add_search((nb % 10), dict_array, str);
		}
	}
	if (!str)
		return (ft_strcat(str, "ERROR"));
	return (str);
}

char	*get_triplet(int nb, char **dict_array, char *str)
{
	if (nb >= 100)
	{
		add_search(nb / 100, dict_array, str);
		ft_strcat(str, " ");
		add_search(100, dict_array, str);
		if (nb % 100 != 0)
			ft_strcat(str, " ");
	}
	if (nb % 100 != 0)
		str = get_doublet_str(nb, dict_array, str);
	if (!str)
		return (ft_strcat(str, "ERROR"));
	return (str);
}
