/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:43:00 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 08:27:43 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_rotate(Stack *stack)
{
    if (stack->size < 2)
        return;
    stack->top = next_down(stack, stack->top);
    stack->bottom = next_down(stack, stack->bottom);
}

void ra(Data *data)
{
    ops_rotate(&data->a);
}

void rb(Data *data)
{
    ops_rotate(&data->b);
}

void rr(Data *data)
{
    ops_rotate(&data->a);
    ops_rotate(&data->b);
}