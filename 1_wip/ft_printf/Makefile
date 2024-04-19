# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/04/19 15:05:33 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRC =		ft_printf.c ft_printf_apply_prec.c ft_printf_apply_spaceplusalt.c \
			ft_printf_apply_width_others.c ft_printf_flags_init.c \
			ft_printf_flags_validate.c ft_printf_gets.c ft_printf_s_utils.c \
			ft_printf_uint_base.c ft_printf_vptr.c ft_printf_apply_prec_s.c \
			ft_printf_d_lens.c

DIRSRC	=	./srcs/
DIRLIBFT=	./srcs/libft/
DIRINC =	./

LIBFT =		$(DIRLIBFT)libft.a
SRCS =      $(addprefix $(DIRSRC), $(SRC)) 
OBJS =		$(SRCS:.c=.o)

NAME =		libftprintf.a

AR =		ar -rcs
RL =		ranlib
RM =		rm -f
GCC =		cc
CFLAGS +=	-Wall -Wextra -Werror
INCLUDES =	-I./ -I$(DIRLIBFT)

# RULES
# **************************************************************************** #

all:		$(LIBFT) $(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@$(RL) $(NAME)
				@echo "\033[32mcompiled $(NAME)\033[0m"

$(LIBFT):
				@$(MAKE) -C $(DIRLIBFT)
				@cp ./srcs/libft/libft.a .
				@mv libft.a $(NAME)

.c.o:
		@$(GCC) $(CFLAGS) $(LINKHEAD) -c $< -o $(<:.c=.o)

bonus:	all

clean:
		@$(RM) $(OBJS) $(OBJSLIBFT)
		@$(MAKE) -C $(DIRLIBFT) clean
		@echo "\033[36mcleaned $(NAME) OBJECTS.\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) -C $(DIRLIBFT) fclean
			@echo "\033[36mcleaned $(NAME) LIBRARY.\033[0m"

re:		fclean all

.PHONY:		all bonus clean fclean re

# **************************************************************************** #
