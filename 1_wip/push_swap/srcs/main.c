/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_stacks(int capacity, char **argv, Stack **a, Stack **b)
{
    init_stack(capacity, b);
    init_stack(capacity, a);
    while (capacity > 0)
        push(*a, ft_atoi(argv[capacity--]));
}

int main(int argc, char **argv)
{
    ft_printf(1, "Start\n\n");
    Stack *a;
    Stack *b;

    validate_arguments(argc, argv);
    create_stacks(argc - 1, argv, &a, &b);
    if (has_duplicates(a))
    {
        // free shit
        // exit
    };
    create_mapper(a);
    print_stack(a);
    // end: free yo shit
    ft_printf(1, "End\n");
}
