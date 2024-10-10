/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:43:00 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/09 16:57:14 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_reverse_rotate(Stack *stack)
{
    if (stack->size < 2)
        return;
    stack->top = next_up(stack, stack->top);
    stack->bottom = next_up(stack, stack->bottom);
}

void rra(Data *data)
{
    ops_reverse_rotate(&data->a);
}

void rrb(Data *data)
{
    ops_reverse_rotate(&data->b);
}

void rrr(Data *data)
{
    ops_reverse_rotate(&data->a);
    ops_reverse_rotate(&data->b);
}