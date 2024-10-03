/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:42:32 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 08:55:17 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(Data *data)
{
    int first;
    int second;
    int third;

    first = value_at_rank(&data->a, 1);
    second = value_at_rank(&data->a, 2);
    third = value_at_rank(&data->a, 3);

    ft_printf(1, "first: %d\n", first);
    ft_printf(1, "second: %d\n", second);
    ft_printf(1, "third: %d\n", third);
}

void sort(Data *data)
{
    // if (data->a.size <= 1 || is_sorted(data))
    //     return;
    // else if (data->a.size == 3)
        sort_three(data);
    // else if (data->a.size == 5)
    //     sort_five_a(data);
    // else
    //     chunk_sort(data);
    // post_sort_optimization();

    return;
}
