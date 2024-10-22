/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:22:21 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/22 17:28:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_a_to_b(t_ps* data)
{
    int node;
    int target;

    node = data->a.cheapest_rank;
    target = get_target(data, node);
    if (is_above_median(&data->a, node) && is_above_median(&data->b, target))
    {
        // do the rr's
    }
    else if (!is_above_median(&data->a, node) && !is_above_median(&data->b, target))
    {
        // do the rrr's
    }
    // do the remainings rotates to have tar and node at the top.
    pb(data);
}