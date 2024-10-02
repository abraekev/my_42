/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:29:16 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 15:59:37 by abraekev         ###   ########.fr       */
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

Stack *init_stack(int capacity)
{
    Stack *stack;

    stack = malloc(sizeof(Stack));
    if (!stack)
        return NULL;
    stack->capacity = capacity;
    stack->stack = malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->mapper = NULL;
    stack->bottom = 0;
    stack->size = 0;
    return stack;
}

void init_data(int argc, char **argv, Data *data)
{
    int a_has_duplicates;
    int numbers_count;

    numbers_count = validate_arguments(argc, argv);
    data->a = init_stack(numbers_count);
    data->a = init_stack(numbers_count);
    if (!(*a) || !(*b))
        error("Malloc failed", free_stack, (*a), (*b));
    if (!assign_values(argc, argv, numbers_count, *a))
        error("Malloc failed", free_stack, (*a), (*b));
    a_has_duplicates = has_duplicates(*a);
    if (a_has_duplicates != 0)
    {
        if (a_has_duplicates == -1)
            error("Malloc failed", free_stack, (*a), (*b));
        error("Duplicate args", free_stack, (*a), (*b));
    }
    if (!create_mapper(*a))
        error("Malloc failed", free_stack, (*a), (*b));
}