/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 11:42:33 by abraekev         ###   ########.fr       */
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
# include <stdlib.h>
# include <stdio.h>

//	MACROS
/******************************************************************************/

//	DEFINITIONS
/******************************************************************************/

// error

void	ft_errno(int i);
void	ft_error(char	*s);
void	ft_big_error(char *s);

//	puts
void	ft_putstr_size(char *s, int size);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

//	split
int		ft_is_charset(char c, char *charset);
int		ft_get_length_out(char *str, char *charset);
int		ft_split_create_str(char **out, char *str, int strlength, int i);
int		ft_split_read_strs(char **out, char *str, char *charset);
char	**ft_split(char *str, char *charset);

//	str 
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *src);
char	*ft_strdup(char *src);
int		ft_strjoin_len(int size, char **strs, char *sep);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strstr(char *str, char *to_find);

//	EXERCISE
/******************************************************************************/

#endif /*FT_H*/