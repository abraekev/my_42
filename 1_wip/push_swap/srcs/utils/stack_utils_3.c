/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:29:16 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 12:30:16 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int assign_values(int argc, char **argv, int numbers_count, Stack *a)
{
    char **args;

    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args)
            return 0;
        while (--numbers_count >= 0)
        {
            push(a, ft_atoi(args[numbers_count]));
            free(args[numbers_count]);
        }
        free(args);
    }
    else
        while (numbers_count > 0)
            push(a, ft_atoi(argv[numbers_count--]));
    return 1;
}

void create_stacks(int argc, char **argv, Stack **a, Stack **b)
{
    int a_has_duplicates;
    int numbers_count;

    numbers_count = validate_arguments(argc, argv);
    (*a) = init_stack(numbers_count);
    (*b) = init_stack(numbers_count);
    if (!(*a) || !(*b))
        error_free("Malloc failed", free_stack, (*a), (*b));
    if (!assign_values(argc, argv, numbers_count, *a))
        error_free("Malloc failed", free_stack, (*a), (*b));
    a_has_duplicates = has_duplicates(*a);
    if (a_has_duplicates != 0)
    {
        if (a_has_duplicates == -1)
            error_free("Malloc failed", free_stack, (*a), (*b));
        error_free("Duplicate args", free_stack, (*a), (*b));
    }
    if (!create_mapper(*a))
        error_free("Malloc failed", free_stack, (*a), (*b));
}