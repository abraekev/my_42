# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/05/03 14:38:35 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRC			=	push_swap.c	t_node_utils.c

DIRSRC		=	./srcs/
DIRLIBFT	=	./srcs/libft/
DIRINC		=	./includes/

LIBFT		=	$(DIRLIBFT)libft.a
SRCS		=	$(addprefix $(DIRSRC), $(SRC)) 
OBJS		=	$(SRCS:.c=.o)

NAME		=	push_swap

GCC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror
MAKEFLAGS	+=	--no-print-directory
LINK		=	-L$(DIRLIBFT) -lft

GREEN		=	\033[032m
CYAN		=	\033[036m
NOCLR		=	\033[0m

# RULES
# **************************************************************************** #

all:			$(LIBFT) $(NAME)

$(NAME):		$(OBJS)
					@$(GCC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINK)
					@printf "$(GREEN)%-12s%-12s\n$(NOCLR)" "compiled" "$(NAME)"
$(LIBFT):
				@$(MAKE) -C $(DIRLIBFT)

.c.o:
		@$(GCC) $(CFLAGS) -I$(DIRINC) -c $< -o $(<:.c=.o)

bonus:	all

clean:
		@$(RM) $(OBJS)
		@$(MAKE) -C $(DIRLIBFT) clean
		@printf "$(CYAN)%-12s%-12sOBJECTS\n$(NOCLR)" "cleaned" "$(NAME)"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) -C $(DIRLIBFT) QUIET=1 fclean
			@printf "$(CYAN)%-12s%-12sPROGRAMS\n$(NOCLR)" "cleaned" "$(NAME)"

re:		fclean all

.PHONY:		all bonus clean fclean re

# **************************************************************************** #
