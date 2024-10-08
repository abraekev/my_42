/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:18:18 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 14:20:01 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static Stack *loc_to_stack(Data *data, Location loc)
{
    if (loc == TOP_A || loc == BOTTOM_A)
        return (&data->a);
    if (loc == TOP_B || loc == BOTTOM_B)
        return (&data->b);
}

void chunk_to_the_top(Data *data, Chunk *chunk)
{
    if (chunk->loc = BOTTOM_B && data->b.size == chunk->size)
        chunk->loc = TOP_B;
    if (chunk->loc = BOTTOM_A && data->a.size == chunk->size)
        chunk->loc - TOP_A;
}

int chunk_value(Data *data, Chunk *chunk, int n)
{
    Location loc;
    Stack *stack;
    int i;

    loc = chunk->loc;
    stack = loc_to_stack(data, loc);
    if (loc == TOP_A || loc == TOP_B)
    {
        i = stack->top;
        while (--n > 0)
            i = next(stack, i);
    }
    else
    {
        i = stack->bottom;
        while (--n > 0)
            i = previous(stack, i);
    }
    return (stack->stack[i]);
}