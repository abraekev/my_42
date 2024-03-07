/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 12:44:46 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

# include <fcntl.h>
# include <unistd.h>

void	ft_putchar(char c, int out);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int out, int len);
void	display_file(char *filepath);

#endif /*DISPLAY_FILE_H*/
