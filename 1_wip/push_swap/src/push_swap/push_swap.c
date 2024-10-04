/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/04 12:57:15 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test(Data data)
{
    ft_printf(1, "original stack top->bottom:\n");
    print_stack(&data.a);

    ft_printf(1, "ra:\n");
    ra(&data);
    print_stack(&data.a);

    ft_printf(1, "pb:\n");
    pb(&data);
    print_stack(&data.a);

    ft_printf(1, "pb:\n");
    pb(&data);
    print_stack(&data.a);

    ft_printf(1, "push a 42:\n");
    push(&data, &data.a, 42);
    print_stack(&data.a);

    ft_printf(1, "sa:\n");
    sa(&data);
    print_stack(&data.a);

    ft_printf(1, "sa:\n");
    sa(&data);
    print_stack(&data.a);

    free_data(&data);
}

int main(int argc, char **argv)
{
    Data data;
    /*  TODO
     *      map values to their rank
     *      remap values after sorting
     */

    // 1. initiate data with arguments
    init_data(validate_arguments(argc, argv), argc, argv, &data);

    ft_printf(1, "before:\n");
    print_stack(&data.a);

    sort(&data);

    ft_printf(1, "after:\n");
    print_stack(&data.a);

    // 3. print operations

    // 4. cleanup operations

    // 5. end
}
