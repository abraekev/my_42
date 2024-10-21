/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:17:46 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/21 15:56:11 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    lowest_cost_push_desc_b(t_ps *data)
{
    while(1) // foreach node in a
    {
    // 1. get_target()
    // 2. calc_cost()
    // 3. update stack->cheapest if cheaper

    // if cost is 0, use this immediately.
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
