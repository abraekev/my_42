/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:14:17 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/09 11:06:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_three_numbers(int *a, int *b, int *c)
{
    int temp;

    if (*a > *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c)
    {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c)
    {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

static int is_consecutive(int a, int b, int c, int d)
{
    sort_three_numbers(&a, &b, &c);
    return ((b - a == 1) && (c - b == 1) && (d - c) == 1);
}

int a_partly_sort(Data *data, int from)
{
    int i;
    Stack *a;
    int value;

    a = &data->a;
    i = a->top;
    while (--from)
        i = next(a, i);
    while (a->stack[i] != data->a.size)
    {
        value = a->stack[i];
        i = next(a, i);
        if (a->stack[i] != value + 1)
            return 0;
    }
    return 1;
}

void split_max_reduction(Data *data, Chunk *chunk)
{
    Stack *a;

    a = &data->a;
    if (chunk->loc = TOP_A && chunk->size == 3 &&
                     is_consecutive(value(a, 1), value(a, 2), value(a, 3), value(a, 4)) &&
                     a_partly_sort(data, 4))
    {
        chunk_sort_three(data, chunk);
        return;
    }
    if (chunk->loc == TOP_A && value(a, 1) == value(a, 3) - 1 && a_partly_sort(data, 3))
    {
        sa(data);
        chunk->size--;
    }
    if (chunk->loc == TOP_A && a_partly_sort(data, 1))
        chunk->size--;
}