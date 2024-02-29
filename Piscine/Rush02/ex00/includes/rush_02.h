/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/25 22:01:03 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

int				*ft_atol(char *src);
int				ft_atol_check(char *src);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			error_msg(char *str);
void			display_file(char *filepath);
char			**create_dict_array_assign(
					int ret, char *buf, int buf_size, int fd);
char			**create_dict_arr(char *filepath, int buf_size);
int				ft_is_charset(char c, char *charset);
int				ft_get_length_out(char *str, char *charset);
int				ft_split_create_str(
					char **out, char *str, int strlength, int i);
int				ft_split_read_strs(char **out, char *str, char *charset);
char			**ft_split(char *str, char *charset);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
int				ft_strlen(char *str);
int				*cut_int(unsigned int number);
int				check_numbers(char *word);
char			*print_nb(int *nb_array, char **dict_array);
char			*get_print(char *search, char **dict_array);
char			*get_suffix(int i, char **dict_array, char *str);
char			*get_triplet(int nb, char **dict_array, char *str);
char			*get_doublet_str(int nb, char **dict_array, char *str);
char			*add_search(int nb, char **dict_array, char *str);
char			*get_doublet_search(int nb);
char			*ft_strcpy(char *dest, char *src);
int				free_all(int *nb_array, char **dict_array, char *out);
void			print_operator(int i, int *a, char *str);
char			*nb_is_zero(char **dict_array, char *str);
char			*ft_strstr(char *str, char *to_find);
int				ft_strncmp(char *s1, char *s2, int n);
char			*value_dict_array(char *dict);
#endif /*RUSH_02_H*/
