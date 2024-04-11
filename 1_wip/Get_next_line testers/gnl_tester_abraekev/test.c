/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/09 21:40:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//# include <fcntl.h>
//# include <sys/stat.h>
//# include <sys/types.h>
//# include <errno.h>
//# include <string.h>
//# include <libgen.h>
//# include <stdio.h>
//# include <limits.h>

//	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get*.c main.c

#define BIGLINENONL "./txts/bigLineNoNewline.txt"
#define BIGLINE "./txts/bigLine.txt"
#define STORY "./txts/story.txt"
#define TESTS "./txts/test.txt"

static int	ft_fd(char *filepath)
{
	return (open(filepath, O_RDONLY));
}

static void	arg_one(int fd)
{
	int	line = 1;
	char	*s = get_next_line(fd);

    printf("\033[32m+++START+++\n");
	while (s)
	{
		printf("\033[34mline %d:\033[0m\n%s", line, s);
		line++;
		free(s);
		s = get_next_line(fd);
	}
	printf("\033[32m+++END+++\n");
}

static int get_one_line_blue(int fd)
{
    static int line = 1;
    char    *s = get_next_line(fd);

	printf("\033[34mline %d:\033[0m\n%s", line, s? s:"(null)\n");
	line++;
    if(s)
    {
        free(s);
        return (1);
    }
    return (0);
}

static int get_one_line_yellow(int fd)
{
    static int line = 1;
    char    *s = get_next_line(fd);

    printf("\033[31mline %d:\033[0m\n%s", line, s? s:"(null)\n");
	line++;
	if(s)
	{
		free(s);
		return (1);
	}
	return (0);
}

static void arg_two(int	fd1, int fd2)
{
	int	a = 1;
	int b = 1;

	while (a || b)
	{
		a = get_one_line_blue(fd1);
		b = get_one_line_yellow(fd2);
	}
}

static void cmpprint(char *buf_fd, char *buf_fp)
{
	if (strcmp(buf_fd, buf_fp) == 0)
    	printf("\033[32m\tOK\033[0m\n");
    else
    	printf("\033[31m\tNOK\033[0m\n");
}

static void	cmpbuff(char *fpath)
{   
    char    *buf_fp = (char *)calloc(12000, 1);
    char    *buf_fd;
    FILE    *fp;
    int     fd;
    int     line_nb = 1;

	fp = fopen(fpath, "r");
    fd = ft_fd(fpath);
	while (fgets(buf_fp, 12000, fp))
    {
        buf_fd = get_next_line(fd);
        printf("line %02d", line_nb);
        cmpprint(buf_fd, buf_fp);
        if (buf_fd)
			free(buf_fd);
		line_nb++;
    }
	free(buf_fp);
	close(fd);
	fclose(fp);
}

static int	cb(FILE *fp, int fd)
{
	char	buf_fp[12000];
	char	*buf_fd;

	if (!fgets(buf_fp, 12000, fp))
		return (0);
	buf_fd = get_next_line(fd);
	if (!buf_fd)
		return (0);
	cmpprint(buf_fd, buf_fp);
	free(buf_fd);
	return(1);
}

static void	check_bonus(char *fpath1, char *fpath2)
{
    FILE    *fp1;
	FILE	*fp2;
    int     fd1;
	int		fd2;
	int     line_nb = 1;

	fp1 = fopen(fpath1, "r");
	fp2 = fopen(fpath2, "r");
	fd1 = ft_fd(fpath1);
	fd2 = ft_fd(fpath2);

	printf("\033[34mline %02d:\033[0m%20s", line_nb, fpath1);	
	int a = cb(fp1, fd1);
	printf("\033[35mline %02d:\033[0m%20s", line_nb++, fpath2);
	int b = cb(fp2, fd2);
	while (a || b)
	{
		printf("\033[34mline %02d:\033[0m%20s", line_nb, fpath1);
		a = cb(fp1, fd1);
		a ? : printf("\tend reached\n");
		printf("\033[35mline %02d:\033[0m%20s", line_nb++, fpath2);
		b = cb(fp2, fd2);
		b ? : printf("\tend reached\n");
	}
} 

static void	test_bonus()
{
	printf("\ntest: %s\n", STORY);
	cmpbuff(STORY);
    printf("\ntest: %s\n", TESTS);
    cmpbuff(TESTS);
    printf("\ntest: %s\n", BIGLINE);
    cmpbuff(BIGLINE);
	printf("\ntest: %s\n", BIGLINENONL);
	cmpbuff(BIGLINENONL);
	
	printf("\n++BONUS++\n");
	check_bonus(STORY, TESTS);
}

int	main(int argc, char **argv)
{
	char	*s;
	
	s = NULL;
	if (argc == 2 && !strcmp("tests", argv[1]))
		test_bonus();
	else if (argc == 2)
		arg_one(ft_fd(argv[1]));
	else if (argc == 3)
	{
		arg_two(ft_fd(argv[1]), ft_fd(argv[2]));
	}
	else if (argc == 1)
	{
		s = get_next_line(2);
		while (s)
		{
			printf("%s", s);
			free(s);
			s = get_next_line(2);
		}
	}
	else
		printf("Error\n");
	return (0);
}
