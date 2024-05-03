/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/05/03 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(char	*str, int position)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = ft_atoi(str);
	new->next = NULL;
	new->previous = NULL;
	new->position = position;
	return (new);
}

t_node	*stck_last(t_node *stck)
{
	while(stck->next)
		stck = stck->next;
	return (stck);
}

void	stck_add_back(t_node **stck, t_node *new)
{
	t_node	*last;

	if (!stck || !new)
		return ;
	if (*stck)
	{
		last = stck_last(*stck);
		last->next = new;
		new->previous = last;
	}
	else
		*stck = new;
}