/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/09/30 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit(char *error_message, int error_code)
{
    if (error_message)
        ft_printf(2, "%s\n", error_message);

    exit(error_code);
}

void error_free(char *error_message, void (*free)(void *), ...)
{
    va_list args;
    void *ptr;

    va_start(args, free);
    while ((ptr = va_arg(args, void *)) != NULL)
        free(ptr);
    va_end(args);
    ft_printf(2, "Error");
    if (error_message)
        ft_printf(2, " - ");
    ft_exit(error_message, 1);
}