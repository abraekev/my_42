/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void validate_single_argument(char *arg, int *numbers_count)
{
    char **numbers_string;
    int i;

    numbers_string = ft_split(arg, ' ');
    *numbers_count = 0;
    while (*(numbers_string + *numbers_count))
    {
        if (!is_valid_int_string(*(numbers_string + *numbers_count)))
        {
            free_str_array(numbers_string);
            ft_exit("ERROR - invalid args", 1);
        }
        (*numbers_count)++;
    }
    free_str_array(numbers_string);
}

static void validate_multiple_arguments(char **argv, int *numbers_count)
{
    while (*argv)
    {
        if (!is_valid_int_string(*argv))
            ft_exit("ERROR - invalid args", 1);
        argv++;
        (*numbers_count)++;
    }
}

int validate_arguments(int argc, char **argv)
{
    int numbers_count;

    if (argc < 2 || !argv)
        ft_exit("ERROR - invalid args", 1);
    if (argc == 2)
        validate_single_argument(argv[1], &numbers_count);
    else
        validate_multiple_arguments(argv + 1, &numbers_count);
    return numbers_count;
}