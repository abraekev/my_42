/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:00:17 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 15:27:09 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]))
			return (1);
	}
	return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>
int f(char *s)
{
	if (*s == 'A')
		return (1);
	return (0);
}
int main (void)
{
	char **array;
	int	i;

	i = 0;
	array = malloc(3 * sizeof(char *));
	array[0] = "Arnout";
	array[1] = "Dit bevat de letter niet.";
	array[2] = NULL;
	while ( i < 3)
	{
		printf("%d\n", ft_any(&array[i], f));
		i++;
	}
}
*/
