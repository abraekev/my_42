# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/04/10 11:19:31 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRCS 	=	$(wildcard *.c) 
#BSRCS	=	./bonus/*.c

OBJS 	=	$(SRCS:.c=.o)
#BOBJS 	=	$(BSRCS:.c=.o)

NAME	=	program

RM =		rm -f
GCC =		cc
CFLAGS +=	-Wall -Wextra -Werror

# RULES
# **************************************************************************** #

.c.o:
			@$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				@$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo program built.

all:		$(NAME)
			@echo "\033[32m\n***EXECUTING***\033[0m\n==============="
			@./$(NAME) tests

#bonus:		$(BOBJS)
#				@$(GCC) $(CFLAGS) $(BOBJS) -o $(NAME)
#				@echo bonus built.

clean:
			@$(RM) $(OBJS)
			@echo cleaned objects.
fclean:		clean
			@$(RM) $(NAME)
			@echo cleaned all.

re:		fclean all

.PHONY:		all clean fclean re
# **************************************************************************** #
