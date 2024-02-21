# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/02/21 22:20:03 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# VARIABLES
# **************************************************************************** #

GCC =		gcc

CFLAGS +=	-Wall -Wextra -Werror

SRC = 		ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
PRE =		./srcs/
SRCS =		$(addprefix $(PRE), $(SRC))
# =		$(wildcard srcs/*.c)

OBJS =		$(SRCS:.c=.o)

INCL =		./includes/

NAME =		libft.a

LIBC =		ar rc

LIBX =		ranlib

CUR_DIR =	$(shell pwd)

# RULES
# **************************************************************************** #

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)
			$(LIBX) $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -c -I $(INCL) $< -o $(<:.c=.o)
#	%.o: %.c
#	"to make a file n.o, look for a file n.c and apply this rule".

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

