/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:59:02 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 08:30:49 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(Data *data)
{
    int i;
    int rank;

    i = data->a.top;
    rank = 1;
    while (rank <= data->a.size)
    {
        if (data->a.stack[i] != rank)
            return 0;
        rank++;
        i = next_down(&data->a, i);
    }
    return 1;
}

int is_full(Data *data, Stack *stack)
{
    return stack->size == data->capacity;
}

int is_empty(Stack *stack)
{
    return stack->size == 0;
}

void print_stack(Stack *stack)
{
    int index;
    int count;


    ft_printf(1, "top %d\n", stack->top);
    ft_printf(1, "bt %d\n", stack->bottom);
    ft_printf(1, "sz %d\n", stack->size);
    ft_printf(1, "T - ");
    if (is_empty(stack))
    {
        ft_printf(1, "Stack is empty\n");
        return;
    }

    index = stack->top;
    count = 0;
    while (count < stack->size)
    {
        ft_printf(1, "%d ", stack->stack[index]);
        index = next_down(stack, index);
        count++;
    }
    ft_printf(1, " - B\n");

}

void free_stack(Stack *stack)
{
    if (!stack)
        return;
    if (stack->stack)
        free(stack->stack);
    if (stack->mapper)
        free(stack->mapper);
    stack->stack = NULL;
    stack->mapper = NULL;
    stack->top = 0;
    stack->size = 0;
}