/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:50:05 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 14:31:12 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_realloc_str(char *old_str, unsigned int new_size)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * new_size);
	if (!new_str)
		return (NULL);
	new_str = ft_strcpy(new_str, old_str);
	free(old_str);
	return (new_str);
}

int	*ft_realloc_int(int *old_ptr, unsigned int new_size)
{
	int	*new_ptr;
	int	i;

	new_ptr = malloc(sizeof(int) * new_size);
	if (!new_ptr)
		return (NULL);
	i = -1;
	while (old_ptr[++i])
		new_ptr[i] = old_ptr[i];
	new_ptr[i] = 0;
	free(old_ptr);
	return (new_ptr);
}
