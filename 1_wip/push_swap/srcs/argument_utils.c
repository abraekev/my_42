/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/05/03 15:37:38 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_argv(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	**tmps;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		tmps = ft_calloc(argc, sizeof(char*));
		if (!tmps)
			return (NULL);
		while(argv[++i])
		{
			tmps[i - 1] = ft_strdup(argv[i]);
			if (!tmps[i - 1])
				return (ft_free_strarr(tmps), NULL);
		}
		tmps[i - 1] = NULL;
		argv = tmps;
	}
	i = -1;
	while(argv[++i])
	{
		tmp = ft_strtrim(argv[i], " \t\n\v\f\r");
		if (!tmp)
			return (ft_free_strarr(argv), NULL);
		free(argv[i]);
		argv[i] = tmp;
	}
	i = -1;
	while (argv[++i])
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (ft_free_strarr(argv), NULL);
		if (!*(argv[i]) || ft_strncmp(argv[i], tmp, ft_strlen(argv[i]) + 1) != 0)
			return (free(tmp), ft_free_strarr(argv), NULL);
		free(tmp);
	}
	return (argv);
}