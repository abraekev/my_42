/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-roec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:06:28 by bde-roec          #+#    #+#             */
/*   Updated: 2024/02/24 20:06:32 by bde-roec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
*/
int	check_numbers(char *word) /* succes = 1, fail = 0 */
{
	int	lettercount;

	lettercount = 0;
	while (word[lettercount] != '\0' )
	{
		if (word[lettercount] > '9' || word[lettercount] < '0')
		{
			return (0);
		}
		lettercount++;
	}
	if (lettercount == 0)
	{
		return (0);
	}
	return (1);
}
/*
int	main(int args, char **input)
	{
	int	number;

	if (input[2] != NULL || input[1] == NULL)
	{
		write (1, "arguments issue\n", 16);
		return (0);
	}
	number = check_numbers(input[1]);
	if (number == 0)
	{
		write (1, "not a valid int\n", 16);
	}
	else
	{
		write (1, "valid input 1\n", 14);
	}
	return (1);
}
*/
