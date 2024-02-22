/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:48:30 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/21 17:21:54 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

/*
#include <stdio.h>
typedef struct s_stock_str
{
	int		size;
	char		*str;
	char		*copy;
}			t_stock_str;
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*out;
	int		len;
	int		i;

	len = ft_strlen(src);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (src[i])
	{
		out[i] = src[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*tab;
	int				i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].copy)
		{
			while (i >= 0)
			{
				free(tab[i].copy);
				i--;
			}
			free(tab);
			return (NULL);
		}
	}
	tab[i].str = 0;
	return (tab);
}

/*
int	main(void)
{
	char 		*av[3];
	av[0] =	"Dit is String 1";
	av[1] = "Dit is String 2";
	av[2] = "Dit is String 3";

	t_stock_str 	*OUT 	= ft_strs_to_tab(3, av);

	printf("===%s===\n", OUT[0].str);
	printf("===%s===\n", OUT[1].copy);
	printf("===%d===\n", OUT[2].size);
	printf("===%s===\n", OUT[3].str);
	return (0);
}


void    ft_struct_free(int i, t_stock_str *tab)
{
        while (i >= 0)
        {
                if (tab[i].str)
                        free(tab[i].str);
                if (tab[i].copy)
                        free(tab[i].copy);
                i--;
        }
        free(tab);
}
*/
