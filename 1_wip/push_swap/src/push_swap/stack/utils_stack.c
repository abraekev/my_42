/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:59:02 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 18:08:09 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_full(Data *data, Stack *stack)
{
    return stack->size == data->capacity;
}

int is_empty(Stack *stack)
{
    return stack->size == 0;
}

void print_stack(Data *data, Stack *stack)
{
    int index = stack->top;

    if (is_empty(stack))
    {
        ft_printf(1, "Stack is empty\n");
        return;
    }

    while (1)
    {
        ft_printf(1, "%d ", stack->stack[index]);
        if (index == stack->bottom)
            break;
        index = ((index - 1) + data->capacity) % data->capacity;
    }
    ft_printf(1, "\n");
}

void free_stack(Stack *stack)
{
    if (!stack)
        return;
    if (stack->stack)
        free(stack->stack);
    if (stack->mapper)
        free(stack->mapper);
    stack->stack = NULL;
    stack->mapper = NULL;
    stack->top = 0;
    stack->size = 0;
}