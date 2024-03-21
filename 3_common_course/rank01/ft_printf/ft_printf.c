/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

//	format specifier:
//	char *fspec = %[flags][min width][precision][conversion specifier]

static char	*get_fspecstr(char *s, size_t i)
{
	char	*convspecs;
	char	*lastchr;
	char	*fspec;
	size_t	j;

	convspecs = "cspdiuxX%";
	j = i + 1;
	while (s[j])
	{
		if (ft_strchr(convspecs, s[j]))
		{
			lastchr = s + j;
			return (ft_substr(s, i, (lastchr - (s + i) + 1)));
		}
		j++;
	}
	return (NULL);
}

static int	process_formatspec(char **s, int i, va_list args)
{
	char	*tmp;
	char	*fspec;
	char	*insert;
	char	convspec;
	size_t	fspec_len;

	fspec = get_fspecstr(*s, i);
	if (!fspec)
		return (0);
	fspec_len = ft_strlen(fspec);
	convspec = fspec[fspec_len - 1];
	insert = get_insertstr(fspec, args, convspec);
	if (!insert)
		return (null_freestrs(1, fspec));
	tmp = update_s(*s, insert, i, fspec_len);
	free(*s);
	if (!tmp)
		return (null_freestrs(2, fspec, insert));
	*s = tmp;
	null_freestrs(2, fspec, insert);
	return (fspec_len);
}

static int	create_s(const char *src, char **s)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	*s = malloc(src_len + 1);
	if (!*s)
		return (0);
	ft_strlcpy(*s, src, src_len + 1);
	return (1);
}

static int	get_len_and_print(char *s)
{
	int	out;

	if (s)
	{
		out = (int)ft_strlen(s);
		ft_putstr_fd(s, 1);
		free(s);
		return (out);
	}
	else
		return (-1);
}

int	ft_printf(const char *src, ...)
{
	char		*s;
	int			ret;
	size_t		i;
	size_t		jump;
	va_list		args;

	va_start(args, src);
	i = -1;
	if (!create_s(src, &s))
		return (-1);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			jump = process_formatspec(&s, i, args);
			if (!jump)
			{
				if (s)
					free(s);
				return (-1);
			}
			i = i + jump - 2;
		}
	}
	return (get_len_and_print(s));
}
