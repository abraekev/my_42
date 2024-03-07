/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 11:42:33 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>

//	MACROS
/******************************************************************************/

//	DEFINITIONS
/******************************************************************************/

//	libft_personal_1
void	ft_putchar(char c);
void	ft_putchar_ult(char c, int fd, int size);
void	ft_putstr(char *str);
void	ft_putstr_ult(char *str, int fd);
//	EXERCISE
/******************************************************************************/

#endif /*LIBFT_H*/
