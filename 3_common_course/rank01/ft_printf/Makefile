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

SRCS =		

OBJS =		$(SRCS:.c=.o)

INCL =		./

NAME =		libftprintf.a	

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

clean:
			$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
# **************************************************************************** #
