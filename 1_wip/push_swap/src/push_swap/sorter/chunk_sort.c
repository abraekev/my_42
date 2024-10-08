/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:05:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 15:11:40 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rec_chunk_sort(Data *data, Chunk *chunk)
{
    Destination dest;

    chunk_to_the_top(data, chunk);
    easy_sort(data, chunk);
}

void chunk_sort(Data *data)
{
    Chunk chunk;

    chunk.loc = TOP_A;
    chunk.size = data->a.size;
    rec_chunk_sort(data, &chunk);
}

void sort_one(Data *data, Chunk *chunk)
{
    if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B || chunk->loc == TOP_B)
        move_from_to(data, chunk->loc, TOP_A);
    chunk->size -= 1;
}