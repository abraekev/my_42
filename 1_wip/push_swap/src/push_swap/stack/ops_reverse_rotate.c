/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:43:00 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 08:55:18 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_reverse_rotate(Stack *stack)
{
    if (stack->size < 2)
        return;
    stack->top = previous(stack, stack->top);
    stack->bottom = previous(stack, stack->bottom);
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