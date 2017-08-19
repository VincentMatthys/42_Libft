/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <dlouise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 02:10:35 by dlouise           #+#    #+#             */
/*   Updated: 2016/11/19 13:55:04 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Les tests definis ici seront effectues
#define TEST_MEMALLOC
#define TEST_MEMDEL
#define TEST_STRNEW
#define TEST_STRDEL
#define TEST_STRCLR
#define TEST_STRITER
#define TEST_STRITERI
#define TEST_STRMAP
#define TEST_STRMAPI
#define TEST_STREQU
#define TEST_STRNEQU
#define TEST_STRSUB
#define TEST_STRJOIN
#define TEST_STRTRIM
#define TEST_STRSPLIT
#define TEST_ITOA
#define TEST_PUTCHAR
#define TEST_PUTSTR
#define TEST_PUTENDL
#define TEST_PUTNBR
#define TEST_PUTCHAR_FD
#define TEST_PUTSTR_FD
#define TEST_PUTENDL_FD
#define TEST_PUTNBR_FD



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include "libft.h"

int     test_memalloc(void);
int		test_memdel(void);
int		test_strnew(void);
int		test_strdel(void);
int		test_strclr(void);
int		test_striter(void);
int		test_striteri(void);
int		test_strmap(void);
int		test_strmapi(void);
int		test_strequ(void);
int		test_strnequ(void);
int		test_strsub(void);
int     test_strjoin(void);
int		test_strtrim(void);
int     test_strsplit(void);
int		test_itoa(void);
int     test_putchar(void);
int     test_putstr(void);
int     test_putendl(void);
int		test_putnbr(void);
int     test_putchar_fd(void);
int     test_putstr_fd(void);
int     test_putendl_fd(void);
int		test_putnbr_fd(void);


#define ERROR() { printf("Line %d, ", __LINE__ - 1); return (0); }
#define ADD_TEST(NAME) add_test(tests_list, #NAME, test_##NAME)

typedef struct	s_test
{
    int         (*f)(void);
    char        *name;
    char        added;
	char		temp[7];
}               t_test;

void    add_test(t_test *tests_list, char *name, int (*f)(void));

void    add_test(t_test *tests_list, char *name, int (*f)(void))
{
    static int  i = 0;

    tests_list[i].f = f;
    tests_list[i].name = name;
    tests_list[i].added = 1;
    i++;
}

int     main(void)
{
    t_test  tests_list[100];
    int     i;
    pid_t   pid;
    int     status;

    memset(tests_list, 0, 100 * sizeof(t_test));


#ifdef TEST_MEMALLOC
    ADD_TEST(memalloc);
#endif
#ifdef TEST_MEMDEL
    ADD_TEST(memdel);
#endif
#ifdef TEST_STRNEW
	ADD_TEST(strnew);
#endif
#ifdef TEST_STRDEL
	ADD_TEST(strdel);
#endif
#ifdef TEST_STRCLR
	ADD_TEST(strclr);
#endif
#ifdef TEST_STRITER
	ADD_TEST(striter);
#endif
#ifdef TEST_STRITERI
	ADD_TEST(striteri);
#endif
#ifdef TEST_STRMAP
	ADD_TEST(strmap);
#endif
#ifdef TEST_STRMAPI
	ADD_TEST(strmapi);
#endif
#ifdef TEST_STREQU
	ADD_TEST(strequ);
#endif
#ifdef TEST_STRNEQU
	ADD_TEST(strnequ);
#endif
#ifdef TEST_STRSUB
	ADD_TEST(strsub);
#endif
#ifdef TEST_STRJOIN
    ADD_TEST(strjoin);
#endif
#ifdef TEST_STRTRIM
	ADD_TEST(strtrim);
#endif
#ifdef TEST_STRSPLIT
    ADD_TEST(strsplit);
#endif
#ifdef TEST_ITOA
	ADD_TEST(itoa);
#endif
#ifdef TEST_PUTCHAR
    ADD_TEST(putchar);
#endif
#ifdef TEST_PUTSTR
    ADD_TEST(putstr);
#endif
#ifdef TEST_PUTENDL
    ADD_TEST(putendl);
#endif
#ifdef TEST_PUTNBR
	ADD_TEST(putnbr);
#endif
#ifdef TEST_PUTCHAR_FD
    ADD_TEST(putchar_fd);
#endif
#ifdef TEST_PUTSTR_FD
    ADD_TEST(putstr_fd);
#endif
#ifdef TEST_PUTENDL_FD
    ADD_TEST(putendl_fd);
#endif
#ifdef TEST_PUTNBR_FD
	ADD_TEST(putnbr_fd);
#endif

    i = 0;
    while (tests_list[i].added)
    {
        printf("ft_%s : ", tests_list[i].name);
        fflush(stdout);
        pid = fork();
        // Cas du fils
        if (0 == pid)
        {
            alarm(3);
            if (1 == tests_list[i].f())
                printf("\033[32mOK\033[0m\n");
            else
                printf("\033[31mKO\033[0m\n");
            exit(0);
        }
        // Cas du pere
        else
        {
            if (-1 != wait(&status) && WIFSIGNALED(status))
            {
                switch(WTERMSIG(status))
                {
                    case SIGSEGV:
                        printf("\033[31mSegmentation Fault\033[0m\n");
                        break;
                    default:
                        printf("\033[31mKO Sig %d\033[0m\n", WTERMSIG(status));
                }
            }
        }

        i++;
    }

    return (0);
}

#ifdef TEST_MEMALLOC
int     test_memalloc(void)
{
	int i;
	char *mem;

	mem = ft_memalloc(5000000);
	for(i = 0; i < 5000000; i++)
	{
		if(0 != mem[i])
        	ERROR();
	}
    return (1);
}
#endif

#ifdef TEST_MEMDEL
int     test_memdel(void)
{
	char *mem;
	char *mem2;
	int pid;
	int status;

	mem = malloc(5000000);
	mem2 = mem;
	ft_memdel((void**)&mem);
    if (mem != NULL)
        ERROR();

	pid = fork();
	if (pid) // Pere
	{
		if ( ! (-1 != wait(&status) && WIFSIGNALED(status)))
			ERROR();
	}
	else // Fils
	{
		fclose(stderr);
		free(mem2);
		exit(0);
	}
    return (1);
}
#endif

#ifdef TEST_STRNEW
int		test_strnew(void)
{
	int		i;
	char	*str;

	str = ft_strnew(5000000);
	i = 0;
    while (i < 5000000)
	{
		if (str[i] != '\0')
			ERROR();
		i++;
	}
	return (1);
}
#endif

#ifdef TEST_STRDEL
int		test_strdel(void)
{

	char *mem;
	char *mem2;
	int pid;
	int status;

	mem = malloc(5000000);
	mem2 = mem;
	ft_strdel((char**)&mem);
    if (mem != NULL)
        ERROR();

	pid = fork();
	if (pid) // Pere
	{
		if ( ! (-1 != wait(&status) && WIFSIGNALED(status)))
			ERROR();
	}
	else // Fils
	{
		fclose(stderr);
		free(mem2);
		exit(0);
	}
    return (1);
}
#endif

#ifdef TEST_STRCLR
int		test_strclr(void)
{
	char	str[10];
	strcpy(str, "abcdefghi");
	str[3] = '\0';

	ft_strclr(str);
	if (0 != memcmp(str, "\0\0\0\0efghi", 10))
		ERROR();

	return (1);
}
#endif

#ifdef TEST_STRITER
void	f1(char* c);
void	f1(char* c)
{
	*c = *c + 1;
}

void	f2(char* c);
void	f2(char* c)
{
	*c = *c - 1;
}

int		test_striter(void)
{
	char	str[10];

	memcpy(str, "abcdef\0hi", 10);

	ft_striter(str, f1);
	if (0 != memcmp(str, "bcdefg\0hi", 10))
		ERROR();

	ft_striter(str, f2);
	if (0 != memcmp(str, "abcdef\0hi", 10))
		ERROR();

	return (1);
}
#endif

#ifdef TEST_STRITERI
void	f3(unsigned int index, char* c);
void	f3(unsigned int index, char* c)
{
	*c = (*c + (char)index);
}

void	f4(unsigned int index, char* c);
void	f4(unsigned int index, char* c)
{
	*c = *c - (char)index;
}

int		test_striteri(void)
{
	char	str[10];

	memcpy(str, "abcdef\0hi", 10);

	ft_striteri(str, f3);
	if (0 != memcmp(str, "acegik\0hi", 10))
		ERROR();

	ft_striteri(str, f4);
	if (0 != memcmp(str, "abcdef\0hi", 10))
		ERROR();

	return (1);
}
#endif

#ifdef TEST_STRMAP
char	f5(char c);
char	f5(char c)
{
	return (c + 1);
}

char	f6(char c);
char	f6(char c)
{
	return (c - 1);
}

int		test_strmap(void)
{
	char	str[10];
	char	*r1;
	char	*r2;

	memcpy(str, "abcdef\0hi", 10);

	r1 = ft_strmap(str, f5);
	if (0 != memcmp(r1, "bcdefg", 7))
		ERROR();

	if (0 != memcmp(str, "abcdef\0hi", 10))
		ERROR();

	r2 = ft_strmap(r1, f6);
	if (0 != memcmp(r2, "abcdef", 7))
		ERROR();

	free(r1);
	free(r2);

	return (1);
}
#endif

#ifdef TEST_STRMAPI
char	f7(unsigned int index, char c);
char	f7(unsigned int index, char c)
{
	return (c + (char)index);
}

char	f8(unsigned int index, char c);
char	f8(unsigned int index, char c)
{
	return ((c - (char)index));
}

int		test_strmapi(void)
{
	char	str[10];
	char	*r1;
	char	*r2;

	memcpy(str, "abcdef\0hi", 10);

	r1 = ft_strmapi(str, f7);
	if (0 != memcmp(r1, "acegik", 7))
		ERROR();

	if (0 != memcmp(str, "abcdef\0hi", 10))
		ERROR();

	r2 = ft_strmapi(r1, f8);
	if (0 != memcmp(r2, "abcdef", 7))
		ERROR();

	free(r1);
	free(r2);

	return (1);
}
#endif

#ifdef TEST_STREQU
int		test_strequ(void)
{
	if (1 != ft_strequ("a", "a"))
		ERROR();
	if (1 != ft_strequ("", ""))
		ERROR();
	if (1 != ft_strequ("abc", "abc"))
		ERROR();
	if (0 != ft_strequ("bbc", "abc"))
		ERROR();
	if (0 != ft_strequ("abb", "abc"))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_STRNEQU
int		test_strnequ(void)
{
	if (1 != ft_strnequ("a", "a", 1000000))
		ERROR();
	if (1 != ft_strnequ("", "", 1000000))
		ERROR();
	if (0 != ft_strnequ("", "aa", 1000000))
		ERROR();
	if (0 != ft_strnequ("aa", "", 1000000))
		ERROR();
	if (0 != ft_strnequ("bbb", "aa", 1000000))
		ERROR();
	if (0 != ft_strnequ("aa", "bbb", 1000000))
		ERROR();
	if (1 != ft_strnequ("abc", "abc", 1000000))
		ERROR();
	if (0 != ft_strnequ("bbc", "abc", 1000000))
		ERROR();
	if (0 != ft_strnequ("abb", "abc", 1000000))
		ERROR();
	if (1 != ft_strnequ("abb", "abc", 2))
		ERROR();
	if (0 != ft_strnequ("abb", "abc", 3))
		ERROR();
	if (1 != ft_strnequ("abc", "abb", 2))
		ERROR();
	if (0 != ft_strnequ("abc", "abb", 3))
		ERROR();
	if (0 != ft_strnequ("ab", "abc", 3))
		ERROR();
	if (0 != ft_strnequ("abc", "ab", 3))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_STRSUB
int		test_strsub(void)
{
	char *str;
	str = ft_strsub("abcdef", 0, 6);
	if (0 != strcmp(str, "abcdef"))
		ERROR();
	free(str);
	str = ft_strsub("abcdef", 1, 3);
	if (0 != strcmp(str, "bcd"))
		ERROR();
	free(str);
	str = ft_strsub("abcdef", 1, 0);
	if (0 != strcmp(str, ""))
		ERROR();
	free(str);

	return (1);
}
#endif

#ifdef TEST_STRJOIN
int     test_strjoin(void)
{
    char    *str;

    str = ft_strjoin("abc", "d");
	if (0 != strcmp(str, "abcd"))
        ERROR();
    free(str);
    str = ft_strjoin("a", "bcd");
	if (0 != strcmp(str, "abcd"))
        ERROR();
    free(str);
    str = ft_strjoin("", "d");
	if (0 != strcmp(str, "d"))
        ERROR();
    free(str);
    str = ft_strjoin("a", "");
	if (0 != strcmp(str, "a"))
        ERROR();
    free(str);

    return (1);
}
#endif

#ifdef TEST_STRTRIM
int		test_strtrim(void)
{
	char *str;

	str = ft_strtrim("\na");
	if (0 != strcmp(str, "a"))
		ERROR();
	free(str);

	str = ft_strtrim("\nab");
	if (0 != strcmp(str, "ab"))
		ERROR();
	free(str);

	str = ft_strtrim("\n \ta\n \t");
	if (0 != strcmp(str, "a"))
		ERROR();
	free(str);

	str = ft_strtrim("a\r ");
	if (0 != strcmp(str, "a\r"))
		ERROR();
	free(str);

	str = ft_strtrim("\na\nb ");
	if (0 != strcmp(str, "a\nb"))
		ERROR();
	free(str);

	str = ft_strtrim("\na  \t");
	if (0 != strcmp(str, "a"))
		ERROR();
	free(str);

	str = ft_strtrim("a");
	if (0 != strcmp(str, "a"))
		ERROR();
	free(str);

	str = ft_strtrim("abc");
	if (0 != strcmp(str, "abc"))
		ERROR();
	free(str);

	// str = ft_strtrim("");
	// if (0 != strcmp(str, ""))
	// 	ERROR();
	// free(str);
	//
	// str = ft_strtrim("\t");
	// if (0 != strcmp(str, ""))
	// 	ERROR();
	// free(str);
	//
	// str = ft_strtrim(" ");
	// if (0 != strcmp(str, ""))
	// 	ERROR();
	// free(str);
	//
	// str = ft_strtrim("\n");
	// if (0 != strcmp(str, ""))
	// 	ERROR();
	// free(str);


	return (1);
}
#endif

#ifdef TEST_STRSPLIT
int     test_strsplit(void)
{
    char    **str;
    char    src[100];

    strcpy(src, "*salut*les***etudiants*");
    str = ft_strsplit(src, '*');
    if (0 != strcmp(str[0], "salut"))
        ERROR();
	if (0 != strcmp(str[1], "les"))
        ERROR();
	if (0 != strcmp(str[2], "etudiants"))
        ERROR();
	if (0 != str[3])
        ERROR();
	if (0 != strcmp(src, "*salut*les***etudiants*"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_ITOA
int		test_itoa(void)
{
	char *str;

	str = ft_itoa(0);
	if (0 != strcmp(str, "0"))
		ERROR();
	free(str);

	str = ft_itoa(-1);
	if (0 != strcmp(str, "-1"))
		ERROR();
	free(str);

	str = ft_itoa(1);
	if (0 != strcmp(str, "1"))
		ERROR();
	free(str);

	str = ft_itoa(-9);
	if (0 != strcmp(str, "-9"))
		ERROR();
	free(str);

	str = ft_itoa(9);
	if (0 != strcmp(str, "9"))
		ERROR();
	free(str);

	str = ft_itoa(-10);
	if (0 != strcmp(str, "-10"))
		ERROR();
	free(str);

	str = ft_itoa(10);
	if (0 != strcmp(str, "10"))
		ERROR();
	free(str);

	str = ft_itoa(-123);
	if (0 != strcmp(str, "-123"))
		ERROR();
	free(str);

	str = ft_itoa(123);
	if (0 != strcmp(str, "123"))
		ERROR();
	free(str);

	str = ft_itoa(-12345);
	if (0 != strcmp(str, "-12345"))
		ERROR();
	free(str);

	str = ft_itoa(12345);
	if (0 != strcmp(str, "12345"))
		ERROR();
	free(str);

	str = ft_itoa(-2147483647 - 1);
	if (0 != strcmp(str, "-2147483648"))
		printf("%s\n", str);
	free(str);

	str = ft_itoa(2147483647);
	if (0 != strcmp(str, "2147483647"))
		ERROR();
	free(str);

	return (1);
}
#endif

#ifdef TEST_PUTCHAR
int     test_putchar(void)
{
	int		out;
	int		p[2];
	char	sortie[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	ft_putchar('a');
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "a"))
    {
	    dup2(out, 1);
        ERROR();
    }

	dup2(out, 1);
    return (1);
}
#endif

#ifdef TEST_PUTSTR
int     test_putstr(void)
{
	int		out;
	int		p[2];
	char	sortie[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	ft_putstr("abc");
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "abc"))
    {
	    dup2(out, 1);
		ERROR();
    }

	dup2(out, 1);
    return (1);
}
#endif

#ifdef TEST_PUTENDL
int     test_putendl(void)
{
	int		out;
	int		p[2];
	char	sortie[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

    ft_putendl("");
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "\n"))
    {
        dup2(out, 1);
		ERROR();
    }

	ft_putendl("abc");
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "abc\n"))
    {
        dup2(out, 1);
		ERROR();
    }

	dup2(out, 1);
    return (1);
}
#endif

#ifdef TEST_PUTNBR
int		test_putnbr(void)
{
	int		out;
	int		p[2];
	char	sortie[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	ft_putnbr(0);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "0"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(-1);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-1"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(1);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "1"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(-99);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-99"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(99);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "99"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(-100);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-100"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(100);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "100"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(-2147483647 - 1);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-2147483648"))
	{
		dup2(out, 1);
		ERROR();
	}

	ft_putnbr(2147483647);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "2147483647"))
	{
		dup2(out, 1);
		ERROR();
	}



	dup2(out, 1);
	return (1);
}
#endif

#ifdef TEST_PUTCHAR_FD
int     test_putchar_fd(void)
{
	int		p[2];
	char	sortie[100];

	pipe(p);

	ft_putchar_fd('a', p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "a"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_PUTSTR_FD
int     test_putstr_fd(void)
{
	int		p[2];
	char	sortie[100];

	pipe(p);

	ft_putstr_fd("abc", p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "abc"))
		ERROR();

    return (1);
}
#endif

#ifdef TEST_PUTENDL_FD
int     test_putendl_fd(void)
{
	int		p[2];
	char	sortie[100];

	pipe(p);

	ft_putendl_fd("", p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "\n"))
		ERROR();

	ft_putendl_fd("abc", p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "abc\n"))
		ERROR();

    return (1);
}
#endif

#ifdef TEST_PUTNBR_FD
int		test_putnbr_fd(void)
{
	int		p[2];
	char	sortie[100];

	pipe(p);

	ft_putnbr_fd(0, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "0"))
		ERROR();

	ft_putnbr_fd(-1, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-1"))
		ERROR();

	ft_putnbr_fd(1, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "1"))
		ERROR();

	ft_putnbr_fd(-99, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-99"))
		ERROR();

	ft_putnbr_fd(99, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "99"))
		ERROR();

	ft_putnbr_fd(-100, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-100"))
		ERROR();

	ft_putnbr_fd(100, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "100"))
		ERROR();

	ft_putnbr_fd(-2147483647 - 1, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "-2147483648"))
	{
		printf("%s\n", sortie);
		ERROR();
	}

	ft_putnbr_fd(2147483647, p[1]);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "2147483647"))
		ERROR();


	return (1);
}
#endif
