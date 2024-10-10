/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:56:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 09:29:46 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push(Data* data, Stack* stack, int value)
{
    int old_size;
    int new_size;
    int i;

    if (is_full(data, stack))
        return 0;
    old_size = stack->size;
    new_size = old_size + 1;
    i = old_size;
    while (--i > stack->top)
        stack->stack[i + 1] = stack->stack[i];
    stack->size = new_size;
    i = next_up(stack, stack->top);
    stack->top = i;
    stack->bottom = next_up(stack, i);
    stack->stack[i] = value;
    return 1;
}

int pop(Data* data, Stack* stack)
{
    int result;
    int old_top;
    int i;

    if (is_empty(stack))
        error(data);
    old_top = stack->top;
    result = stack->stack[old_top];
    stack->size -= 1;
    i = old_top;
    while (i < stack->size)
    {
        stack->stack[i] = stack->stack[i + 1];
        i++;
    }
    stack->top = next_down(stack, old_top);
    stack->bottom = next_up(stack, stack->top);
    return result;
}