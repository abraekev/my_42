/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	total;

	if (nmemb && size > (SIZE_MAX / nmemb))
		return (NULL);
	total = nmemb * size;
	out = malloc(total);
	if (!out)
		return (NULL);
	ft_bzero(out, total);
	return (out);
}
