/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 11:42:33 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

//	MACROS
/******************************************************************************/

# define BUFFER_SIZE 64

typedef struct s_data
{
	int		eof;
	int		index;
	int		bytes_read;
	char	*substr;
	char	buffer[BUFFER_SIZE + 1];
}		t_data;

//	DEFINITIONS
/******************************************************************************/

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t d_size);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		newline_found(t_data *data);
int		add_buff_to_out(char *out, t_data *data);

#endif /*GET_NEXT_LINE_H*/
