/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:40 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//	HEADERS
/******************************************************************************/

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

//	MACROS
/******************************************************************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif /*BUFFER_SIZE*/

//	STRUCTS & ENUMS
/******************************************************************************/

//	DEFINITIONS
/******************************************************************************/

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif /*GET_NEXT_LINE_H*/
