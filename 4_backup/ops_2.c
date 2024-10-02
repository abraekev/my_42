/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ops_rotate(Stack *stack)
{
    if (stack->size < 2)
        return;
    stack->top = next(stack, stack->top);
    stack->bottom = next(stack, stack->bottom);
}

void ops_reverse_rotate(Stack *stack)
{
    if (stack->size < 2)
        return;
    stack->top = previous(stack, stack->top);
    stack->bottom = previous(stack, stack->bottom);
}

void ops_rotate_both(Stack *x, Stack *y)
{
    ops_rotate(x);
    ops_rotate(y);
}

void ops_reverse_rotate_both(Stack *x, Stack *y)
{
    ops_reverse_rotate(x);
    ops_reverse_rotate(y);
}