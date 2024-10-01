/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
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
        ft_exit("ERROR - allocation failed", 1);
    i = stack->bottom;
    compare_size = 0;
    while (1)
    {
        j = 0;
        while (j < compare_size)
            if (stack->buffer[i] == compare[j++])
            {
                free(compare);
                return 0;
            }
        compare[compare_size++] = stack->buffer[i];
        i = previous(stack, i);
        if (i == stack->bottom)
            break;
    }
    free(compare);
    return 1;
}