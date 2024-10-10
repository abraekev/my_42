/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/10 09:20:18 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void test(Data data)
{
  ft_printf(1, "original stack top->bottom:\n");
  print_stack(&data.a);

  ft_printf(1, "ra:\n");
  ra(&data);
  print_stack(&data.a);

  ft_printf(1, "pb:\n");
  pb(&data);
  print_stack(&data.a);

  ft_printf(1, "pb:\n");
  pb(&data);
  print_stack(&data.a);

  ft_printf(1, "push a 42:\n");
  push(&data, &data.a, 42);
  print_stack(&data.a);

  ft_printf(1, "sa:\n");
  sa(&data);
  print_stack(&data.a);

  ft_printf(1, "sa:\n");
  sa(&data);
  print_stack(&data.a);

  free_data(&data);
}

int main(int argc, char** argv)
{
  Data data;

  // 1. initiate data & sort
  //init_data(validate_arguments(argc, argv), argc, argv, &data);


  init_stack(&data, &data.a, 99);

  ft_printf(1, "\n==BEFORE==\n");
  print_stack(&data.a);

  ft_printf(1, "\n==push==\n");
  push(&data, &data.a, 55);
  push(&data, &data.a, 99);
  push(&data, &data.a, 11);
  push(&data, &data.a, 44);
  push(&data, &data.a, 66);
  print_stack(&data.a);

  ft_printf(1, "\n==3 x ra==\n");
  ra(&data);
  ra(&data);
  ra(&data);
  print_stack(&data.a);


  ft_printf(1, "\n==2 x pop==\n");
  pop(&data, &data.a);
  pop(&data, &data.a);
  print_stack(&data.a);


  ft_printf(1, "\n==4 x rra==\n");
  rra(&data);
  rra(&data);
  rra(&data);
  rra(&data);
  print_stack(&data.a);

  ft_printf(1, "\n==push==\n");
  push(&data, &data.a, 69);
  print_stack(&data.a);
  // 2. sort the data
  //sort(&data);

  //ft_printf(1, "==AFTER==\n");
  //print_stack(&data.a);

  // 3. print operations
  // 4. cleanup operations
  // 5. end



  // todo:
  // implement subfunctions of  sort_three.c  
}
