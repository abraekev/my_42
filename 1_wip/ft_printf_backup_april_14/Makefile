# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/04/12 17:50:50 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

SRC =		ft_printf.c ft_printf_apply_prec.c ft_printf_apply_spaceplusalt.c \
			ft_printf_apply_width_others.c ft_printf_flags_init.c \
			ft_printf_flags_validate.c ft_printf_gets.c ft_printf_s_utils.c \
			ft_printf_uint_base.c ft_printf_vptr.c

DIRINCL	=	./includes/
DIRSRC	=	./srcs/
DIRLIBFT=	./srcs/libft/

LIBFT =		libft.a
SRCS =      $(addprefix $(DIRSRC), $(SRC)) 
OBJSLIBFT =	$(DIRLIBFT)*.o
OBJS =		$(SRCS:.c=.o)

NAME =		libftprintf.a

AX = 		ar -x
AR =		ar -rcs
RL =		ranlib
RM =		rm -f
GCC =		cc
CFLAGS +=	-Wall -Wextra -Werror

# RULES
# **************************************************************************** #

.c.o:
		@$(GCC) $(CFLAGS) -c -I $(DIRINCL) $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(OBJSLIBFT)
				@$(AR) $(NAME) $(OBJS) $(OBJSLIBFT)
				@$(RL) $(NAME)
				@echo "compilation \t\tSUCCESS."

all:		$(NAME)

#bonus:	all

main:
			@$(GCC) -g test*.c -I $(DIRINCL) $(NAME)

$(OBJSLIBFT):	
		@cd $(DIRLIBFT) && $(AX) $(LIBFT)
		@echo "extract libft.a \tSUCCESS."

clean:
		@$(RM) $(OBJS) $(OBJSLIBFT)
		@echo "cleaned objects."

fclean:		clean
			@$(RM) $(NAME)
			@echo "cleaned $(NAME)."

re:		fclean all

.PHONY:		all bonus clean fclean re main extract
# **************************************************************************** #
