/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 15:16:07 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicates(Stack *stack)
{
    int *compare;
    int compare_size;
    int i;
    int j;

    compare = malloc((stack->capacity) * sizeof(int));
    if (!compare)
        return -1;
    i = stack->bottom;
    compare_size = 0;
    while (1)
    {
        j = 0;
        while (j < compare_size)
            if (stack->stack[i] == compare[j++])
            {
                free(compare);
                return 1;
            }
        compare[compare_size++] = stack->stack[i];
        i = previous(stack, i);
        if (i == stack->bottom)
            break;
    }
    free(compare);
    return 0;
}