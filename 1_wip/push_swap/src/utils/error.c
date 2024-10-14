/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 11:55:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_data(t_ps *data)
{
    if (!data)
        return;
    free_stack(&data->a);
    free_stack(&data->b);
}

void error(t_ps *data)
{
    free_data(data);
    ft_printf(2, "Error\n");
    exit(EXIT_FAILURE);
}