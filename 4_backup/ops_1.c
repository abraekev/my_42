/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 15:17:17 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ops_swap(Stack *stack)
{
    int tmp;

    if (stack->size < 2)
        return;
    tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[(stack->top) - 1];
    stack->stack[(stack->top) - 1] = tmp;
}

void ops_swap_both(Stack *x, Stack *y)
{
    ops_swap(x);
    ops_swap(y);
}

void ops_push_from_to(Stack *x, Stack *y)
{
    if (x->size < 1)
        return;
    push(y, x->stack[x->top]);
    pop(x);
}