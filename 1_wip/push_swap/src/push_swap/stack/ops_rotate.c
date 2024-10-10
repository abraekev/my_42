/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:43:00 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 11:55:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_rotate(t_stack *stack)
{
    if (stack->size < 2)
        return;
    stack->top = next_down(stack, stack->top);
    stack->bottom = next_down(stack, stack->bottom);
}

void ra(t_ps *data)
{
    ops_rotate(&data->a);
}

void rb(t_ps *data)
{
    ops_rotate(&data->b);
}

void rr(t_ps *data)
{
    ops_rotate(&data->a);
    ops_rotate(&data->b);
}