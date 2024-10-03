/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:59:02 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 11:58:38 by abraekev         ###   ########.fr       */
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

void print_stack(Stack *stack)
{
    int index;
    int count;

    ft_printf(1, "T - ");
    if (is_empty(stack))
    {
        ft_printf(1, "Stack is empty\n");
        return;
    }

    index = stack->top;
    count = 0;
    while (count < stack->size)
    {
        ft_printf(1, "%d ", stack->stack[index]);
        index = next(stack, index);
        count++;
    }
    ft_printf(1, " - B\n");
    ft_printf(1, "top %d\n", stack->top);
    ft_printf(1, "bt %d\n", stack->bottom);
    ft_printf(1, "sz %d\n\n", stack->size);
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