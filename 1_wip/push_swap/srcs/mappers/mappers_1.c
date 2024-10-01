/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void replace_buffer(Stack *stack)
{
    int i = 0;
    int j;

    // Iterate over buffer to replace values with their mapped ranks
    while (i < stack->size)
    {
        j = 0;
        while (j < stack->size)
        {
            if (stack->buffer[i] == stack->mapper[j])
            {
                stack->buffer[i] = (j + 1); // Replace buffer value with its rank
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
            if (i != j && stack->buffer[i] > stack->buffer[j])
                index++;
            j++;
        }
        stack->mapper[index] = stack->buffer[i++];
    }
    replace_buffer(stack);
    return 1;
}