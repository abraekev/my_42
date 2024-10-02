/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 12:40:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void recursive_sort(Stack *a, Stack *b, int pivot1, int pivot2)
{
}

int main(int argc, char **argv)
{
    // start
    ft_printf(1, "Start\n\n");

    Stack *a;
    Stack *b;

    create_stacks(argc, argv, &a, &b);
    print_stack(a);

    recursive_sort(a, b, 0, 0);

    free_stack(a);
    free_stack(b);

    // end
    ft_printf(1, "End\n");
}
