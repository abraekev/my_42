/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/09 11:44:24 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void test(Data data)
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

    // 1. initiate data & sort
    init_data(validate_arguments(argc, argv), argc, argv, &data);

    ft_printf(1, "\n==BEFORE==\n");
    print_stack(&data.a);

    // 2. sort the data
    sort(&data);

    ft_printf(1, "==AFTER==\n");
    print_stack(&data.a);

    // 3. print operations
    // 4. cleanup operations
    // 5. end



    // todo:
    // implement subfunctions of  sort_three.c  
}
