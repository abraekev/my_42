# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/02/25 21:00:18 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

MAIN_SRC = ./main/main.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)

GCC =		cc

CFLAGS +=	-Wall -Wextra -Werror

SRCS  =		$(wildcard srcs/*.c)

OBJS =		$(SRCS:.c=.o)

INCL =		./includes/

EXEC =		rush-02

LIB = 		rush-02.a

LIBC =		ar rc

LIBX =		ranlib

CUR_DIR =	$(shell pwd)

# RULES
# **************************************************************************** #

all: 		$(LIB) $(EXEC)

$(EXEC):	$(LIB) $(MAIN_OBJ)
			$(GCC) $(CFLAGS) -I $(INCL) -o $(EXEC) $(MAIN_OBJ) -L. $(LIB)

$(LIB):		$(OBJS)
			$(LIBC) $(LIB) $(OBJS)
			$(LIBX) $(LIB)

.c.o:
			$(GCC) $(CFLAGS) -c -I $(INCL) $< -o $(<:.c=.o)
#	%.o: %.c
#	"to make a file name.o, look for a file name.c and apply this rule".
#	-c staat voor "compile given .c files into seperate .o files"
#	-I staat voor "kijk in deze dir voor alle header .h files"

clean:
			rm -f $(OBJS)
			rm -f $(MAIN_OBJ)
fclean:		clean
			rm -f $(LIB)
			rm -f $(EXEC)

re:			fclean all

# **************************************************************************** #
