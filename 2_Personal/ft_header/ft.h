/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:32:57 by abraekev         ###   ########.fr       */
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

		// puts
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
		// split
int		ft_is_charset(char c, char *charset);
int		ft_get_length_out(char *str, char *charset);
int		ft_split_create_str(char **out, char *str, int strlength, int i);
int		ft_split_read_strs(char **out, char *str, char *charset);
char    **ft_split(char *str, char *charset);
		// str 
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlength(char *src);
char	*ft_strdup(char *src);

#endif /*FT_H*/
