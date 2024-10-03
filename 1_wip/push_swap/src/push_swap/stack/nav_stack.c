/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:24:37 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/03 08:55:16 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int next(Stack *stack, int index)
{
    return (index - 1 + stack->size) % stack->size;
}

int previous(Stack *stack, int index)
{
    return (index + 1) % stack->size;
}

int value_at_rank(Stack *stack, int rank)
{
    int index;

    index = (stack->top - rank + 1 + stack->size) % stack->size;
    return (stack->stack[index]);
}