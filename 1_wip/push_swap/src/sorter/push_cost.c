/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:45:20 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/22 16:27:45 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_above_median(t_stack* stack, int rank)
{
    return (rank <= (stack->size / 2) + 1);
}

int get_push_cost(t_ps* data, int rank, int target)
{
    // push cost = (# ops to bring node a on top) + (# ops to bring node a's target node on top)
    // dont forget to take the median into account. (size / 2)

    int push_cost;

    push_cost = rank - 1;
    if (!is_above_median(&data->a, rank))
        push_cost = data->a.size - rank + 1;
    if (is_above_median(&data->b, target))
        push_cost += target - 1;
    else
        push_cost += (data->b.size - target + 1);
    return (push_cost);
}