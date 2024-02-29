/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-roec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:45:25 by bde-roec          #+#    #+#             */
/*   Updated: 2024/02/24 19:52:35 by bde-roec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>*/
#include <stdlib.h>
/*#include <stdio.h>*/

int	*cut_int(unsigned int number)
{
	int	*array;
	int	hundreds;
	int	thousands;
	int	millions;
	int	billion;

	hundreds = (number % 1000);
	number = (number - hundreds);
	thousands = (number % 1000000);
	thousands /= 1000;
	number = (number - thousands);
	millions = (number % 1000000000);
	millions /= 1000000;
	number = (number - millions);
	billion = (number / 1000000000);
	array = malloc(sizeof(int) * 4);
	if (!array)
		return (NULL);
	array[0] = hundreds;
	array[1] = thousands;
	array[2] = millions;
	array[3] = billion;
	return (array);
}
/*
int	main(int arg, char **str)
{
	int				*cutnumber;
	unsigned int	number;

	number = 1222333444;
	cutnumber = cut_int(number);
	printf("%d\n", cutnumber[0]);
	printf("%d\n", cutnumber[1]);
	printf("%d\n", cutnumber[2]);
	printf("%d\n", cutnumber[3]);
	return (1);
}
*/
