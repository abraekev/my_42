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

SRCS =		ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = 	ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS =		$(SRCS:.c=.o)

BOBJS =		$(BSRCS:.c=.o)

INCL =		./

NAME =		libft.a	

LIBC =		ar rc

LIBX =		ranlib

RM =		rm -f

# RULES
# **************************************************************************** #

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				$(LIBC) $(NAME) $(OBJS)
				$(LIBX) $(NAME)

all:		$(NAME)

bonus:		$(NAME) $(BOBJS)
				$(LIBC) $(NAME) $(BOBJS)
				$(LIBX) $(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
# **************************************************************************** #
