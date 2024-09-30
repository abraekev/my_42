/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_int(char *input)
{
    int number;
    char *result;
    int is_valid;

    if (!input || !*input)
        return 0;
    number = ft_atoi(input);
    result = ft_itoa(number);
    is_valid = (ft_strcmp(input, result) == 0);
    free(result);
    return (is_valid);
}

void validate_single_argument(char *arg, int *numbers_count)
{
    char **numbers_string;
    int i;

    numbers_string = ft_split(arg, ' ');
    *numbers_count = 0;
    while (*(numbers_string + *numbers_count))
    {
        if (!is_valid_int(*(numbers_string + *numbers_count)))
        {
            free_str_array(numbers_string);
            ft_exit("ERROR", 1);
        }
        (*numbers_count)++;
    }
    free_str_array(numbers_string);
}

int validate_arguments(int argc, char **argv)
{
    int numbers_count;

    if (argc < 2 || !argv)
        ft_exit("ERROR", 1);
    if (argc == 2)
        validate_single_argument(argv[1], &numbers_count);
    else
        validate_multiple_arguments(argv, &numbers_count);
    return numbers_count;
}