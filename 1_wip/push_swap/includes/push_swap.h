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
#define PUSH_SWAP_H

//	HEADERS
/******************************************************************************/

#include "libft.h"

//	MACROS
/******************************************************************************/

//	STRUCTS & ENUMS
/******************************************************************************/

typedef struct s_circular_stack
{
	int *buffer;
	int top;
	int size;
	int capacity;
} Stack;

//	DEFINITIONS
/******************************************************************************/

// exist_utils
void ft_exit(char *errorMessage, int errorCode);

// malloc_utils
void free_str_array(char **array);

// stack_utils_1
Stack *init_stack(int capacity);
int is_full(Stack *stack);
int is_empty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);

// stack_utils_2
int peek(Stack *stack);
void free_stack(Stack *stack);
void print_stack(Stack *stack);

// validation
int validate_arguments(int argc, char **argv);
int is_valid_int_string(const char *str);

#endif /*PUSH_SWAP_H*/