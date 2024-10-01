/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    Stack *a;
    Stack *b;
    int good_arguments;
    a = NULL;
    b = NULL;

    good_arguments = validate_arguments(argc, argv);
    ft_printf(1, "args\t\t%d\ngood args\t%d\n", argc - 1, good_arguments);
}
