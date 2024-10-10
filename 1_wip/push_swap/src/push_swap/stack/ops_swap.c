/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:57:20 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 11:55:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_swap(t_stack *stack)
{
    int original_top_value;
    int top;
    int second;

    if (stack->size < 2)
        return;
    original_top_value = stack->stack[stack->top];
    top = stack->top;
    second = next_down(stack,top);
    stack->stack[top] = stack->stack[second];
    stack->stack[second] = original_top_value;
}

void sa(t_ps *data)
{
    ops_swap(&data->a);
}

void sb(t_ps *data)
{
    ops_swap(&data->b);
}

void ss(t_ps *data)
{
    ops_swap(&data->a);
    ops_swap(&data->b);
}