/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:18:18 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/09 16:57:14 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack* loc_to_stack(Data* data, Location loc)
{
    if (loc == TOP_A || loc == BOTTOM_A)
        return (&data->a);
    else
        return (&data->b);
}

void chunk_to_the_top(Data* data, Chunk* chunk)
{
    if (chunk->loc == BOTTOM_B && data->b.size == chunk->size)
        chunk->loc = TOP_B;
    if (chunk->loc == BOTTOM_A && data->a.size == chunk->size)
        chunk->loc = TOP_A;
}

int chunk_value(Data* data, Chunk* chunk, int n)
{
    Location loc;
    Stack* stack;
    int i;

    loc = chunk->loc;
    stack = loc_to_stack(data, loc);
    if (loc == TOP_A || loc == TOP_B)
    {
        i = stack->top;
        while (--n > 0)
            i = next_down(stack, i);
    }
    else
    {
        i = stack->bottom;
        while (--n > 0)
            i = next_up(stack, i);
    }
    return (stack->stack[i]);

    // is next and previous correct here?
}

int chunk_max_value(Data* data, Chunk* chunk)
{
    Stack* stack;
    int size;
    int max_value;
    int i;

    stack = loc_to_stack(data, chunk->loc);
    size = chunk->size;
    max_value = 0;
    if (chunk->loc == TOP_A || chunk->loc == TOP_B)
        i = stack->top;
    else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
        i = stack->bottom;
    while (size--)
    {
        if (stack->stack[i] > max_value)
            max_value = stack->stack[i];
        if (chunk->loc == TOP_A || chunk->loc == TOP_B)
            i = next_down(stack, i);
        else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
            i = next_up(stack, i);
    }
    return (max_value);
}