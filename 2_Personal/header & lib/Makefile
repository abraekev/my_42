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

SRC =		#.c files here !!
PRE =		./srcs/
SRCS =		$(addprefix $(PRE), $(SRC))

OBJS =		$(SRCS:.c=.o)

INCL =		./includes/

NAME =		libft	

LIB = 		$(NAME).a
LIBC =		ar rc
LIBX =		ranlib

#CUR_DIR =	$(shell pwd)

# RULES
# **************************************************************************** #

all:		$(LIB)

$(LIB):		$(OBJS)
				$(LIBC) $(LIB) $(OBJS)
				$(LIBX) $(LIB)

$(NAME):	$(OBJS)
				$(GCC) $(CFLAGS) -I $(INCL) -o $(NAME) $(OBJS)

.c.o:
			$(GCC) $(CFLAGS) -c -I $(INCL) $< -o $(<:.c=.o)
#	%.o: %.c
#	"to make a file name.o, look for a file name.c and apply this rule".
#	-c staat voor "compile given .c files into seperate .o files"
#	-I staat voor "kijk in deze dir voor alle header .h files"

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)
				rm -f $(LIB)

re:			fclean all

# **************************************************************************** #
