/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 12:19:02 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int peek(Stack *stack)
{
    if (is_empty(stack))
        ft_exit("ERROR - Empty stack", 1);
    return stack->buffer[stack->top];
}

void free_stack(void *ptr)
{
    Stack *stack = (Stack *)ptr;
    if (!stack)
        return;
    if (stack->buffer)
        free(stack->buffer);
    if (stack->mapper)
        free(stack->mapper);
    stack->buffer = NULL;
    stack->mapper = NULL;
    stack->capacity = 0;
    stack->top = -1;
    stack->size = 0;
    free(stack);
}

void print_stack(Stack *stack)
{
    int index = stack->top;

    if (is_empty(stack))
    {
        ft_printf(1, "Stack is empty\n");
        return;
    }

    while (1)
    {
        ft_printf(1, "%d ", stack->buffer[index]);
        if (index == stack->bottom)
            break;
        index = ((index - 1) + stack->capacity) % stack->capacity;
    }
    ft_printf(1, "\n");
}

int next(Stack *stack, int index)
{
    return (index - 1 + stack->capacity) % stack->capacity;
}

int previous(Stack *stack, int index)
{
    return (index + 1) % stack->capacity;
}