/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/05/03 13:58:41 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack *init_stack(int capacity)
{
    Stack *stack;

    stack = malloc(sizeof(Stack));
    if (!stack)
        return NULL;
    stack->capacity = capacity;
    stack->buffer = malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->mapper = NULL;
    stack->bottom = 0;
    stack->size = 0;
    return stack;
}

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
    stack->buffer[stack->top] = value;
    stack->size++;
}

int pop(Stack *stack)
{
    int result;

    if (is_empty(stack))
        ft_exit("Stack underflow", 1);
    result = stack->buffer[stack->top];
    stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
    stack->size--;
    return result;
}
