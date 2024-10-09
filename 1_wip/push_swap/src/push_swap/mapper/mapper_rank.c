/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:41:22 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 12:41:30 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void replace_buffer(Stack *stack)
{
    int i = 0;
    int j;

    // Iterate over stack to replace values with their mapped ranks
    while (i < stack->size)
    {
        j = 0;
        while (j < stack->size)
        {
            if (stack->stack[i] == stack->mapper[j])
            {
                stack->stack[i] = (j + 1); // Replace stack value with its rank
                break;
            }
            j++;
        }
        i++;
    }
}

int create_mapper(Stack *stack)
{
    int index;
    int i;
    int j;

    i = 0;
    stack->mapper = malloc(sizeof(int) * stack->size);
    if (!stack->mapper)
        return 0;
    while (i < stack->size)
    {
        index = 0;
        j = 0;
        while (j < stack->size)
        {
            if (i != j && stack->stack[i] > stack->stack[j])
                index++;
            j++;
        }
        stack->mapper[index] = stack->stack[i++];
    }
    replace_buffer(stack);
    return 1;
}