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

typedef struct s_flags
{
	char	cspec;
	int		just_l;
	int		pad_zero;
	int		pref_space;
	int		pref_plus;
	int		alt_print;
	int		min_width;
	int		precision;
}	t_flags;

//	DEFINITIONS
/******************************************************************************/

	// ft_printf_apply_width_others.c
char	*apply_width_others(char *s, t_flags f);

	// ft_printf_apply_prec.c
char	*apply_precision(char *s, t_flags f);

	// ft_printf_apply_spaceplusalt.c
char	*add_prefix(char *s, char *prefix);
char	*apply_spaceplus(char *s, t_flags f);
char	*apply_altprint(char *s, t_flags f);

	// ft_print_vptr_base.c
char	*get_vptr_base(uintptr_t nbr);

	// ft_printf_uint_base.c
char	*get_uint_base(unsigned int nbr, char c);

	// ft_printf_flags_init.c
t_flags	initiate_flags(void);
int		get_flags(char *fspec, t_flags *flags);

	// ft_print_flags_validate.c
int		validate_flags(char *s, t_flags *flags);

	// ft_printf_gets.c
char	*apply_flags(char *s, t_flags f);
char	*get_char(char c);
char	*get_str(char *s);
char	*get_insertstr(char *fspec, va_list args, char convspec);	

	// ft_printf_s_utils.c
int		zero_freestrs(size_t n, ...);
char	*null_freestrs(size_t n, ...);
char	*update_s(char *s, char *insert, size_t i, size_t fspec_len);

	// ft_printf.c
int		ft_printf(const char *s, ...);

#endif /*FT_PRINTF_H*/
