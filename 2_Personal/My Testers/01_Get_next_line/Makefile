# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/04/10 18:10:55 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRCS 	=	get_next_line.c get_next_line_utils.c test.c 
BSRCS	=	get_next_line_bonus.c get_next_line_utils_bonus.c test.c

NAME	=	program

RM =		rm -f
GCC =		cc
CFLAGS +=	-Wall -Wextra -Werror -D BUFFER_SIZE=

BS		=	1

ifeq ($(MAKECMDGOALS),bonus)
	SRCS	=	$(BSRCS)
	NAME	=	bonusprogram
endif

BUILD	=	$(GCC) $(CFLAGS)$(BS) $(SRCS) -o $(NAME)

# RULES
# **************************************************************************** #

all:
		$(GCC) $(CFLAGS)$(BS) $(SRCS) -o $(NAME)
		@echo "\033[36m\n***$(NAME) BUFFERSIZE=$(BS)***\033[0m"
		@echo "\033[36m========================================================\033[0m"
		@./$(NAME) tests
		$(eval BS=42)
		$(GCC) $(CFLAGS)$(BS) $(SRCS) -o $(NAME)
		@echo "\033[36m\n***$(NAME) BUFFERSIZE=$(BS)***\033[0m"
		@echo "\033[36m========================================================\033[0m"
		@./$(NAME) tests
		$(eval BS=9999)
		$(GCC) $(CFLAGS)$(BS) $(SRCS) -o $(NAME)
		@echo "\033[36m\n***$(NAME) BUFFERSIZE=$(BS)***\033[0m"
		@echo "\033[36m========================================================\033[0m"
		@./$(NAME) tests

bonus:		all

clean:
			@$(RM) $(OBJS)
			@echo cleaned objects.

fclean:		clean
			@$(RM) program
			@$(RM) bonusprogram 
			@echo cleaned all.

re:		fclean all

.PHONY:		all clean fclean re bonus
# **************************************************************************** #
