/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 11:42:33 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//	HEADERS
/******************************************************************************/

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

//	needed for variadic functions
# include <stdarg.h>

//	MACROS
/******************************************************************************/

//	STRUCTS & ENUMS
/******************************************************************************/

//	DEFINITIONS
/******************************************************************************/

char	*get_insertstr(char *fspec, va_list args, char convspec);
char	*get_percent(void);
int		null_freestrs(size_t n, ...);
char	*update_s(char *s, char *insert, size_t i, size_t fspec_len);

int		ft_printf(const char *s, ...);

#endif /*FT_PRINTF_H*/
