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

SRC =		ft_printf.c ft_printf_apply_prec.c ft_printf_apply_spaceplusalt.c ft_printf_apply_width_others.c ft_printf_flags_init.c ft_printf_flags_validate.c ft_printf_gets.c ft_printf_s_utils.c ft_printf_uint_base.c ft_printf_vptr.c

DIRINCL	=	./includes/
DIRSRC	=	./srcs/
LIBFT	=	./libft/libft.a

SRCS =		$(addprefix $(DIRSRC), $(SRC))
OBJS =		$(SRCS:.c=.o)

NAME =		libftprintf.a	

AR =		ar rcs
RL =		ranlib
RM =		rm -f
GCC =		cc
CFLAGS +=	-Wall -Wextra -Werror

# RULES
# **************************************************************************** #

.c.o:
			$(GCC) $(CFLAGS) -c -I $(DIRINCL) $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				$(AR) $(NAME) $(OBJS)
				$(RL) $(NAME)

main:		$(NAME)
			$(GCC) main.c testing.c -I $(DIRINCL) $(NAME) $(LIBFT)
			make clean

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re main make
# **************************************************************************** #
