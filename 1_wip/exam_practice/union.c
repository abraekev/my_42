/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:48:49 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 17:11:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$

$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$

$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$

$>./union | cat -e
$
$>

$>./union "rien" | cat -e
$
$>

*/

int	comes_before(char *str, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		if (str[i] == str[j])
			return (1);
	}
	return (0);
}

void	ft_union(char *one, char *two)
{
	int i;
	int	j;

	i = -1;
	while (one[++i])
	{
		if (!comes_before(one, i))
			write(1, &one[i], 1);
	}
	i = -1;
	while (two[++i])
	{
		if (!comes_before(one,ft_strlen(one)) && ! comes_before(two, i))
			write(1, &two[i], 1);
	}
}

int	main(int c, char **v)
{
	if (c != 3)
	{
		ft_putstr("\n");
		return 0;
	}
	ft_union(v[1], v[2]);
	return 0;
}
