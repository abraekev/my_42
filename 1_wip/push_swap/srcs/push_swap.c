/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/05/03 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str, int exit_code)
{
	ft_printf(2, "%s\n", str);
	exit(exit_code);
}

t_node	*init_stack(int argc, char **argv, t_node *a)
{
	int		i;
	int		position;
	t_node	*new;

	i = -1;
	position = 0;
	if (argc != 2)
		i++;
	while (argv[++i])
	{
		new = create_node(argv[i], position++);
		if (!new)
		{}	/***error***/
		stck_add_back(&a, new);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;	
	if (argc == 1)
		ft_exit("Error", 0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = init_stack(argc, argv, a);
	(void)b;
	while (a)
	{
		ft_printf(1, "node op positie %d bevat value %d (prev: %d)\n", a->position, a->value, (a->previous) ? a->previous->value: 0);
		a = a->next;
	}
	return (0);
}
