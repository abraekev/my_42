/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:04:50 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/14 11:32:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void eliminate_neutral_op(t_list* ops)
{
    t_list* ref;
    t_list* cmp;
    t_op op_neutral;

    ref = ops->next;
    while (ref && ref->next)
    {
        op_neutral = neutral_op(get_op(ref));
        if (op_neutral)
        {
            cmp = ref->next;
            while (!op_on_same_stack(get_op(ref), get_op(cmp))
                && get_op(cmp) != op_neutral && cmp->next)
                cmp = cmp->next;

            // t_list needs previous attribute to continue this ...
            // update libft.
        }
    }
}

void optimize_ops(t_ps* data)
{
    if (!data->ops)
        return;
    eliminate_neutral_op(data->ops);
}