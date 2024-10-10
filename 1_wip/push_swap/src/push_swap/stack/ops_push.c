/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:10:53 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 09:33:32 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ops_push_from_to(Data* data, Stack* x, Stack* y)
{
    if (x->size < 1)
        return;
    if (!push(data, y, x->stack[x->top]))
        error(data);
    pop(data, x);
}

void pa(Data* data)
{
    ops_push_from_to(data, &data->b, &data->a);
};

void pb(Data* data)
{
    ops_push_from_to(data, &data->a, &data->b);
};