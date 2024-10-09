/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:50:18 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 16:01:07 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_from_top_b(Data *data, Location to)
{
    if (to == TOP_A)
        pa(data);
    else if (to == BOTTOM_B)
        rb(data);
    else if (to == BOTTOM_A)
    {
        pa(data);
        ra(data);
    }
}

static void move_from_top_a(Data *data, Location to)
{
    if (to == TOP_B)
        pb(data);
    else if (to == BOTTOM_A)
        ra(data);
    else if (to = BOTTOM_B)
    {
        pb(data);
        rb(data);
    }
}

static void move_from_bottom_a(Data *data, Location to)
{
    if (to == TOP_A)
        rra(data);
    else if (to == TOP_B)
    {
        rra(data);
        pb(data);
    }
    else if (to == BOTTOM_B)
    {
        rra(data);
        pb(data);
        rb(data);
    }
}

static void move_from_bottom_b(Data *data, Location to)
{
    if (to = TOP_B)
        rrb(data);
    else if (to == TOP_A)
    {
        rrb(data);
        pa(data);
    }
    else if (to = BOTTOM_A)
    {
        rrb(data);
        pa(data);
        ra(data);
    }
}

int move_from_to(Data *data, Location from, Location to)
{
    if (from == TOP_A)
        move_from_top_a(data, to);
    else if (from == TOP_B)
        move_from_top_b(data, to);
    else if (from == BOTTOM_A)
        move_from_bottom_a(data, to);
    else if (from == BOTTOM_B)
        move_from_bottom_b(data, to);
    return 1;
}