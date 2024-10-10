/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/09 16:57:14 by abraekev         ###   ########.fr       */
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

typedef enum e_location
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
} Location;

typedef struct s_chunk
{
	Location loc;
	int size;
} Chunk;

typedef struct s_split_destination
{
	Chunk min;
	Chunk mid;
	Chunk max;
} Destination;

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

// mapper
int create_mapper(Stack *stack);

// push_swap
int main(int argc, char **argv);

// sorter
int a_partly_sort(Data *data, int from);
void chunk_sort(Data *data);
void chunk_to_the_top(Data *data, Chunk *chunk);
int chunk_value(Data *data, Chunk *chunk, int n);
int chunk_max_value(Data *data, Chunk *chunk);
void chunk_sort_one(Data *data, Chunk *chunk);
void chunk_sort_three(Data *data, Chunk *chunk);
void chunk_sort_two(Data *data, Chunk *chunk);
void chunk_split(Data *data, Chunk *chunk, Destination *dest);
void easy_sort(Data *data, Chunk *chunk);
Stack *loc_to_stack(Data *data, Location loc);
int move_from_to(Data *data, Location from, Location to);
void sort(Data *data);
void split_max_reduction(Data *data, Chunk *chunk);

// stack
void fill_stack(int argc, char **argv, Data *data);
void free_stack(Stack *stack);
int is_empty(Stack *stack);
int is_full(Data *data, Stack *stack);
int is_sorted(Data *data);
void init_stack(Data *data, Stack *stack, int size);
int next_down(Stack *stack, int index);
int pop(Data *data, Stack *stack);
int next_up(Stack *stack, int index);
void print_stack(Stack *stack);
int push(Data *data, Stack *stack, int value);
int value(Stack *stack, int rank);
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