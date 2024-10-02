/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 15:59:37 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_full(Stack *stack)
{
    return stack->size == stack->capacity;
}

int is_empty(Stack *stack)
{
    return stack->size == 0;
}

void push(Stack *stack, int value)
{
    if (is_full(stack))
        ft_exit("Stack overflow", 1);

    stack->top = (stack->top + 1) % stack->capacity;
    stack->stack[stack->top] = value;
    stack->size++;
}

int pop(Stack *stack)
{
    int result;

    if (is_empty(stack))
        ft_exit("Stack underflow", 1);
    result = stack->stack[stack->top];
    stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
    stack->size--;
    return result;
}
