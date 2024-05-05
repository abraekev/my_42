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
	if (str)
		ft_printf(2, "%s\n", str);
	exit(exit_code);
}

t_node	*init_stack(char **argv, t_node *a)
{
	int		i;
	int		position;
	t_node	*new;

	i = -1;
	position = 0;
	while (argv[++i])
	{
		new = stck_create_node(argv[i], position++);
		if (!new)
		{}	/***error***/
		stck_add_back(&a, new);
	}

	return (ft_free_strarr(argv), a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;	
	if (argc == 1)
		ft_exit(NULL, 0);
	argv = get_argv(argc, argv);
	if (!argv)
		ft_exit("Invalid arguments. Please provide a list of positive and/or negative integers.", 0); /*check opgave voor print statement*/
	a = init_stack(argv, a);
	(void)b;
	while (a)
	{
		ft_printf(1, "Node op positie %d bevat value %d (prev: %d)\n", a->position, a->value, (a->previous) ? a->previous->value: 0);
		a = a->next;
	}
	return (0);
}