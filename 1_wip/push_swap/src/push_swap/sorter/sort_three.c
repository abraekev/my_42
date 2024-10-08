/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:04:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 16:59:05 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_top_a(Data *data, Chunk *chunk, Stack *stack, int max)
{
    if (stack->stack[stack->top] == max)
    {
        sa(data);
        ra(data);
        sa(data);
        rra(data);
    }
    else if (stack->stack[next(stack, stack->top)] == max)
    {
        ra(data);
        sa(data);
        rra(data);
    }
    chunk->loc = TOP_A;
    chunk->size -= 1;
    sort_two(data, chunk);
}

void sort_three(Data *data, Chunk *chunk)
{
    Stack *stack;
    int max;

    stack = loc_to_stack(data, chunk->loc);
    max = chunk_max_value(data, chunk);
    if (chunk->loc == TOP_A)
        sort_three_top_a(data, chunk, stack, max);
    else if (chunk->loc == BOTTOM_A)
        sort_three_bottom_a();
    else if (chunk->loc == TOP_B)
        sort_three_top_b();
    else if (chunk->loc == BOTTOM_B)
        sort_three_bottom_b();
}
