/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:12:25 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/14 11:27:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op neutral_op(t_op op)
{
    if (op == PA)
        return (PB);
    if (op == PB)
        return (PB);
    if (op == RA)
        return (RRA);
    if (op == RB)
        return (RRB);
    if (op == RRA)
        return (RA);
    if (op == RRB)
        return (RB);
    if (op == SA)
        return (SA);
    if (op == SB)
        return (SB);
    if (op == RR)
        return (RRR);
    return (NULL_OP);
}

t_op get_op(t_list* node)
{
    return ((t_op)(uintptr_t)node->content);
}

int op_on_same_stack(t_op ref, t_op to_check)
{
    if (ref == PA || ref == PB || ref == RR || ref == RRR)
        return 1;
    if (to_check == PA || to_check == PB || to_check == RR || to_check == RRR)
        return 1;
    else if (ref == RA || ref == RRA || ref == SA)
        return (to_check == RA || to_check == RRA || to_check == SA);
    else if (ref == RB || ref == RRB || ref == SB)
        return (to_check == RB || to_check == RRB || to_check == SB);
    return NULL_OP;
}