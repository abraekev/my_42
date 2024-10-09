/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:24:37 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/08 14:19:27 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int next(Stack *stack, int index)
{
    if (!stack->size)
        return index;
    return (index - 1 + stack->size) % stack->size;
}

int previous(Stack *stack, int index)
{
    if (!stack->size)
        return index;
    return (index + 1) % stack->size;
}

int value(Stack *stack, int position)
{
    int index;

    index = (stack->top - position + 1 + stack->size) % stack->size;
    return (stack->stack[index]);
}