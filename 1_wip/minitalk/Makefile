# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/04/30 16:35:10 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRCSERV		=	server.c
SRCCLNT		=	client.c

DIRSRC		=	./srcs/
DIRLIBFT	=	./srcs/libft/
DIRINC		=	./includes/

LIBFT		=	$(DIRLIBFT)libft.a
SRCSSERV	=	$(addprefix $(DIRSRC), $(SRCSERV)) 
SRCSCLNT	=	$(addprefix $(DIRSRC), $(SRCCLNT))
OBJSSERV	=	$(SRCSSERV:.c=.o)
OBJSCLNT	=	$(SRCSCLNT:.c=.o)

NAMESERV	=	server
NAMECLNT	=	client

AR			=	ar -rcs
RL			=	ranlib
RM			=	rm -f
GCC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror
MAKEFLAGS	+=	--no-print-directory

# RULES
# **************************************************************************** #

all:		$(LIBFT) $(NAME)

$(NAME):	$(LIBFT) $(OBJSSERV) $(OBJSCLNT)
				$(GCC) $(CFLAGS) $(OBJSSERV) -o $(NAMESERV)
				$(GCC) $(CFLAGS) $(OBJSCLNT) -o $(NAMECLNT)				
#VOEG HIER NOG DE LINKER NAAR DE LIBRARY TOE

$(LIBFT):
				@$(MAKE) -C $(DIRLIBFT)

.c.o:
		@$(GCC) $(CFLAGS) -I$(DIRINC) -c $< -o $(<:.c=.o)

bonus:	all

clean:
		@$(RM) $(OBJS) $(OBJSLIBFT)
		@$(MAKE) -C $(DIRLIBFT) clean
		@echo "\033[36mcleaned $(NAME) OBJECTS.\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) -C $(DIRLIBFT) QUIET=1 fclean
			@echo "\033[36mcleaned $(NAME) LIBRARY.\033[0m"

re:		fclean all

.PHONY:		all bonus clean fclean re

# **************************************************************************** #
