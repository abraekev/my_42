/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:24:37 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 19:31:34 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int next(Data *data, Stack *stack, int index)
{
    return (index - 1 + data->capacity) % data->capacity;
}

int previous(Data *data, Stack *stack, int index)
{
    return (index + 1) % data->capacity;
}