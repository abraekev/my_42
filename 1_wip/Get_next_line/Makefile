# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/04/05 16:49:27 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRC 	=	get_next_line.c get_next_line_utils.c main.c
DIRINCL	=	./
DIRSRC	=	./
DIRLIBFT=	./srcs/libft/

OBJS =		$(SRCS:.c=.o)
SRCS =		$(addprefix $(DIRSRC), $(SRC))

NAME =		program	

AX = 		ar -x
AR =		ar -rcs
RL =		ranlib
RM =		rm -f
GCC =		cc
CFLAGS +=	-Wall -Wextra -Werror

# RULES
# **************************************************************************** #

.c.o:
			$(GCC) $(CFLAGS) -c -I $(DIRINCL) $< -o $(<:.c=.o)

$(NAME):
			$(GCC) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
# **************************************************************************** #
