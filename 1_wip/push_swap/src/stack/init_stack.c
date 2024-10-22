/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:34:50 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/22 15:15:15 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_ps *data, t_stack *stack, int size)
{
	stack->stack = malloc(sizeof(int) * size);
	if (!stack->stack)
		error(data);
	stack->mapper = NULL;
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
	stack->cheapest_cost = INT_MAX;
	stack->cheapest_rank = 0;
	ft_memset(stack->stack, 0, sizeof(int) * size);
}
