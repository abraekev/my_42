/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:14:38 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 08:56:06 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void duplicate_check(Data *data, Stack *stack)
{
    int *compare;
    int compare_size;
    int i;
    int j;

    compare = malloc((data->capacity) * sizeof(int));
    if (!compare)
        error(data);
    i = stack->bottom;
    compare_size = 0;
    while (1)
    {
        j = 0;
        while (j < compare_size)
            if (stack->stack[i] == compare[j++])
            {
                free(compare);
                error(data);
            }
        compare[compare_size++] = stack->stack[i];
        i = previous(stack, i);
        if (i == stack->bottom)
            break;
    }
    free(compare);
}