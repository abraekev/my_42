/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:17:46 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/22 17:28:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_target(t_ps* data, int node) // verified
{
    // closest smaller number to node in b, else its the max value in b.
    int target;
    int rank;
    int delta;

    target = -1;
    rank = 1;
    delta = INT_MAX;
    while (rank <= data->b.size)
    {
        if (value(&data->b, rank) < node &&
            node - value(&data->b, rank) < delta)
        {
            target = rank;
            delta = node - value(&data->b, rank);
        }
        rank++;
    }
    if (target == -1)
        return rank_max(&data->b);
    return target;
}

static void    lowest_cost_push_desc_b(t_ps* data)
{
    int rank;
    int target;
    int push_cost;

    rank = 1;
    while (rank <= data->a.size) // for each node in a
    {
        // 1. get_target()
        target = get_target(data, value(&data->a, rank));

        // 2. calc_cost()
        push_cost = get_push_cost(data, rank, target);

        // 3. update stack->cheapest if cheaper
        if (push_cost < data->a.cheapest_cost)
        {
            data->a.cheapest_cost = push_cost;
            data->a.cheapest_rank = rank;
        }

        // if cost is 0, use this immediately.
        if (data->a.cheapest_cost == 0)
            break;

        rank++;
    }

    // 4. execute the push: (39:40)
        // bring a to top
        // bring target to top
        // pb(data);
    move_a_to_b(data);
    
    // 5. reset stack->cheapest
    data->a.cheapest_cost = INT_MAX;
	data->a.cheapest_rank = 0;
}

static void    push_first_two(t_ps* data)
{
    if (data->a.size > 3 && !is_sorted(data))
        pb(data);
    if (data->a.size > 3 && !is_sorted(data))
        pb(data);
}

void	sort_stacks(t_ps* data)
{
    push_first_two(data);
    while (data->a.size > 3 && !is_sorted(data))
        lowest_cost_push_desc_b(data);

    // sort the 3 remaining nodes.
    if (data->a.size == 3)
        sort_three(data);

    // push back to a.
}
