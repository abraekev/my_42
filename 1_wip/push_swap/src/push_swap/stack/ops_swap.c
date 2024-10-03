/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:57:20 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 11:30:52 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_swap(Stack *stack)
{
    int tmp;

    if (stack->size < 2)
        return;
    tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[(stack->top) - 1];
    stack->stack[(stack->top) - 1] = tmp;
}

void sa(Data *data)
{
    ops_swap(&data->a);
}

void sb(Data *data)
{
    ops_swap(&data->b);
}

void ss(Data *data)
{
    ops_swap(&data->a);
    ops_swap(&data->b);
}