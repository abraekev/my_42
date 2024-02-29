/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 10:51:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

//	MACROS
/******************************************************************************/

# define BUF_SIZE 29950 

//	DEFINITIONS
/******************************************************************************/

//	ft_1
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_size(char *s, int size);
void	ft_putnbr(int nb);

//	ft_3
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *src);

//	ft_4
int		ft_strjoin_len(int size, char **strs, char *sep);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strstr(char *str, char *to_find);

//	ft_error
void	ft_ult_putchar(char c, int out, int size);
void	ft_ult_putstr(char *str, int out, int len);
void	ft_errno(int i);
void	ft_error(char *s);
void	ft_big_error(char *s);

//	EXERCISE
/******************************************************************************/
void	read_error(char *filepath);
int		ft_cat(char *filepath);
void	cat_error(char **argv, int i);
void	no_arg(char **argv);

#endif /*FT_H*/
