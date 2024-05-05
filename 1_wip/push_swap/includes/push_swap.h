/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/05/03 13:58:41 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	HEADERS
/******************************************************************************/

#include "libft.h"

//	MACROS
/******************************************************************************/

//	STRUCTS & ENUMS
/******************************************************************************/

typedef struct s_stack_node
{
	int					value;
	int					position;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_node;

//	DEFINITIONS
/******************************************************************************/

//***t_node_utils.c
t_node	*stck_create_node(char	*str, int position);
t_node	*stck_last(t_node *stck);
void	stck_add_back(t_node **stck, t_node *new);

//***allocation_utils.c
void	ft_free_strarr(char **strs);

//***argument_utils.c
char	**get_argv(int argc, char **argv);

#endif /*PUSH_SWAP_H*/