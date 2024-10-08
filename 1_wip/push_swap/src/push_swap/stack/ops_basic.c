/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:56:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 14:11:45 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_value(Data *data, Stack *stack, int value)
{
    stack->top = (stack->top + 1) % data->capacity;
    stack->stack[stack->top] = value;
    stack->size++;
}

int push(Data *data, Stack *stack, int value)
{
    int i;

    if (is_full(data, stack))
        return 0;
    if (stack->bottom != 0)
    {
        i = data->capacity;
        while (--i > stack->top + 1)
            stack->stack[i] = stack->stack[i - 1];
        stack->bottom = (stack->bottom + 1) % data->capacity;
    }
    push_value(data, stack, value);
    return 1;
}

static int pop_value(Data *data, Stack *stack)
{
    int result;

    result = stack->stack[stack->top];
    stack->top = (stack->top - 1 + stack->size) % stack->size;
    stack->size--;
    return result;
}

int pop(Data *data, Stack *stack)
{
    int result;
    int i;

    if (is_empty(stack))
        error(data);
    result = pop_value(data, stack);
    if (stack->bottom != 0)
    {
        i = stack->bottom - 1;
        while (i < stack->size - 1)
        {
            stack->stack[i] = stack->stack[i + 1];
            i++;
        }
        stack->bottom = (stack->bottom - 1 + stack->size) % stack->size;
    }
    return result;
}