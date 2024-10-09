/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:34:50 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/02 16:48:08 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(Data *data, Stack *stack, int size)
{
    stack->stack = malloc(sizeof(int) * size);
    if (!stack->stack)
        error(data);
    stack->mapper = NULL;
    stack->top = -1;
    stack->bottom = 0;
    stack->size = 0;
    ft_memset(stack->stack, 0, sizeof(int) * size);
}