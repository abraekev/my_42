/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_std.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:56:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 17:13:06 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push(Data *data, Stack *stack, int value)
{
    if (is_full(data, stack))
        return 0;

    stack->top = (stack->top + 1) % data->capacity;
    stack->stack[stack->top] = value;
    stack->size++;
    return 1;
}

int pop(Data *data, Stack *stack)
{
    int result;

    if (is_empty(stack))
        error(data);
    result = stack->stack[stack->top];
    stack->top = (stack->top - 1 + data->capacity) % data->capacity;
    stack->size--;
    return result;
}