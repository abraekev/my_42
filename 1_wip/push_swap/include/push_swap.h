/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/04 12:54:20 by abraekev         ###   ########.fr       */
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

typedef struct s_circular_array_stack
{
	int *stack;
	int *mapper;
	int top;
	int bottom;
	int size;
} Stack;

typedef struct s_push_swap_data
{
	Stack a;
	Stack b;
	int capacity;
} Data;

//	DEFINITIONS
/******************************************************************************/

// push_swap
int main(int argc, char **argv);

// sorter
void sort(Data *data);

// stack
void fill_stack(int argc, char **argv, Data *data);
void free_stack(Stack *stack);
int is_empty(Stack *stack);
int is_full(Data *data, Stack *stack);
int is_sorted(Data *data);
void init_stack(Data *data, Stack *stack, int size);
int next(Stack *stack, int index);
int pop(Data *data, Stack *stack);
int previous(Stack *stack, int index);
void print_stack(Stack *stack);
int push(Data *data, Stack *stack, int value);
int value_at_rank(Stack *stack, int rank);
void pa(Data *data);
void pb(Data *data);
void ra(Data *data);
void rb(Data *data);
void rr(Data *data);
void rra(Data *data);
void rrb(Data *data);
void rrr(Data *data);
void sa(Data *data);
void sb(Data *data);
void ss(Data *data);

// utils
void error(Data *data);
void free_data(Data *data);
void free_str_array(char **array);
void init_data(int capacity, int argc, char **argv, Data *data);

// validation
int validate_arguments(int argc, char **argv);
int is_valid_int_string(const char *str);
void duplicate_check(Data *data, Stack *stack);

#endif /*PUSH_SWAP_H*/