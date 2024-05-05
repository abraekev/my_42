/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/05/03 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_strarr(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
	{
		free(strs[i]);
		strs[i] = NULL;
	}
	free(strs);
}