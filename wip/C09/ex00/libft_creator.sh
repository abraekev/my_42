# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 19:55:01 by abraekev          #+#    #+#              #
#    Updated: 2024/02/21 20:30:59 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#rm -f libft.a
cc -c -Wall -Werror -Wextra ft_*.c
ar rc libft.a *.o
ranlib libft.a
#rm -f *.o
