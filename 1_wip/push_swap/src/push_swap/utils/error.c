/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 08:29:22 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_data(Data *data)
{
    if (!data)
        return;
    if (&data->a)
        free_stack(&data->a);
    if (&data->b)
        free_stack(&data->b);
}

void error(Data *data)
{
    free_data(data);
    ft_printf(2, "Error\n");
    exit(EXIT_FAILURE);
}