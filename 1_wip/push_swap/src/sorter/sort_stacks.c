/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:17:46 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/21 16:29:19 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_target(t_ps *data, int node)
{
    // closest smaller number to node in b, else its the max value in b.
    int target;
    int rank;
    int delta;

    target = -1;
    rank = 1;
    delta = INT_MAX;
    while(rank <= data->b.size)
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
        // create get max value or rank of stack b.
        return get_max();
    return target;
}

void    lowest_cost_push_desc_b(t_ps *data)
{
    int rank;

    rank = 1;
    while(rank <= data->a.size) // foreach node in a
    {
        // 1. get_target()
        get_target(data, value(&data->a, rank));
        
        // 2. calc_cost()
        // 3. update stack->cheapest if cheaper

        // if cost is 0, use this immediately.
        rank++;
    }

    // 4. execute the push:
        // bring a to top
        // bring target to top
        // pb(data);
    // 5. reset stack->cheapest
    
}

void    push_first_two(t_ps *data)
{
    if (data->a.size > 3 && !is_sorted(data))
        pb(data);
    if (data->a.size > 3 && !is_sorted(data))
        pb(data);
}

void	sort_stacks(t_ps *data)
{
    push_first_two(data);    
    while (data->a.size > 3 && !is_sorted(data))
        lowest_cost_push_desc_b(data);

    // sort the 3 remaining nodes.
    if (data->a.size == 3)
        sort_three(data);
    
    // push back to a.
}
