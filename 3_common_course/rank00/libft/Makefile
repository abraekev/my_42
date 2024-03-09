# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/02/27 14:49:42 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

GCC =		cc

CFLAGS +=	-Wall -Wextra -Werror

SRCS =		ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c

OBJS =		$(SRCS:.c=.o)

INCL =		./

NAME =		libft.a	

LIBC =		ar rc

LIBX =		ranlib

# RULES
# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJS)
				$(LIBC) $(NAME) $(OBJS)
				$(LIBX) $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -c -I $(INCL) $< -o $(<:.c=.o)

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

# **************************************************************************** #
