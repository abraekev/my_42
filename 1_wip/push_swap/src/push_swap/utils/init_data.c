/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:10:51 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 17:11:57 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_data(int capacity, int argc, char **argv, Data *data)
{
    data->capacity = capacity;
    init_stack(data, &data->a, capacity);
    init_stack(data, &data->b, capacity);
    fill_stack(argc, argv, data);
}
