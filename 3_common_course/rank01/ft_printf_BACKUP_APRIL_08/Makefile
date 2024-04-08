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

SRC =		ft_printf.c ft_printf_apply_prec.c ft_printf_apply_spaceplusalt.c ft_printf_apply_width_others.c ft_printf_flags_init.c ft_printf_flags_validate.c ft_printf_gets.c ft_printf_s_utils.c ft_printf_uint_base.c ft_printf_vptr.c

DIRINCL	=	./includes/
DIRSRC	=	./srcs/
DIRLIBFT=	./srcs/libft/

LIBFT =		libft.a
OBJSLIBFT =	$(DIRLIBFT)*.o
OBJS =		$(SRCS:.c=.o)
SRCS =		$(addprefix $(DIRSRC), $(SRC))

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
		$(GCC) $(CFLAGS) -c -I $(DIRINCL) $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(OBJSLIBFT)
				$(AR) $(NAME) $(OBJS) $(OBJSLIBFT)
				$(RL) $(NAME)

all:		$(NAME)

main:
			$(GCC) -g test*.c -I $(DIRINCL) $(NAME)

$(OBJSLIBFT):	
		cd $(DIRLIBFT) && $(AX) $(LIBFT)
		
clean:
		$(RM) $(OBJS) $(OBJSLIBFT)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re main extract
# **************************************************************************** #
