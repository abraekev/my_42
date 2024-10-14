/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/14 11:04:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
  t_ps data;

  // 1. initiate data & sort
  init_data(validate_arguments(argc, argv), argc, argv, &data);

  // 2. sort the data
  sort(&data);

  // 3. print operation log
  print_log(&data);

  // 4. cleanup
  free_data(&data);

  exit(EXIT_SUCCESS);
}
