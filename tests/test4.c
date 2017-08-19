/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:32:19 by vmatthys          #+#    #+#             */
/*   Updated: 2016/11/17 10:56:12 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Les tests definis ici seront effectues

#define TEST_LSTPUSH_BACK
#define TEST_WORD_LEN
#define TEST_PUTSTRTAB
#define TEST_COUNT_WORDS
#define TEST_IS_IN_STR
#define TEST_STRSPLITSTR
#define TEST_STRSPLIT_TOLST
#define TEST_PRINT_MEMORY
#define TEST_ITOABASE
#define TEST_CONVERT_BASE
// #define TEST_PRINT_LIST
#define TEST_STRLCPY
#define TEST_ATOI2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include "libft.h"

int		test_lstpush_back(void);
int		test_word_len(void);
int		test_putstrtab(void);
int		test_count_words(void);
int		test_is_in_str(void);
int		test_strsplitstr(void);
int		test_strsplit_tolst(void);
int		test_print_memory(void);
int		test_itoabase(void);
int		test_convert_base(void);
int		test_print_list(void);
int		test_strlcpy(void);
int		test_atoi2(void);

#define ERROR() { printf("Line %d, ", __LINE__ - 1); return (0); }
#define ADD_TEST(NAME) add_test(tests_list, #NAME, test_##NAME)

typedef struct  s_test
{
    int         (*f)(void);
    char        *name;
    char        added;
	char		pad[7];
}               t_test;

void	add_test(t_test *tests_list, char *name, int (*f)(void));
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


#ifdef TEST_LSTPUSH_BACK
	ADD_TEST(lstpush_back);
#endif
#ifdef TEST_WORD_LEN
	ADD_TEST(word_len);
#endif
#ifdef TEST_PUTSTRTAB
	ADD_TEST(putstrtab);
#endif
#ifdef TEST_COUNT_WORDS
	ADD_TEST(count_words);
#endif
#ifdef TEST_IS_IN_STR
	ADD_TEST(is_in_str);
#endif
#ifdef TEST_STRSPLITSTR
	ADD_TEST(strsplitstr);
#endif
#ifdef TEST_STRSPLIT_TOLST
	ADD_TEST(strsplit_tolst);
#endif
#ifdef TEST_PRINT_MEMORY
	ADD_TEST(print_memory);
#endif
#ifdef TEST_PRINT_LIST
	ADD_TEST(print_list);
#endif
#ifdef TEST_ITOABASE
	ADD_TEST(itoabase);
#endif
#ifdef TEST_CONVERT_BASE
	ADD_TEST(convert_base);
#endif
#ifdef TEST_PRINT_LIST
	ADD_TEST(print_list);
#endif
#ifdef TEST_STRLCPY
	ADD_TEST(strlcpy);
#endif
#ifdef TEST_ATOI2
	ADD_TEST(atoi2);
#endif

	i = 0;
	while (tests_list[i].added)
	{
		printf("ft_%s : ", tests_list[i].name);
		fflush(stdout);
		pid = fork();
		if (0 == pid)
		{
			alarm(3);
			if (1 == tests_list[i].f())
				printf("\033[32mOK\033[0m\n");
			else
				printf("\033[31mKO\033[0m\n");
			exit(0);
		}
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

#ifdef TEST_LSTPUSH_BACK
int		test_lstpush_back(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;
	t_list	*stock;

	n1 = ft_lstnew("Ecrevisse", strlen("Ecrevisse"));
	lst = n1;
	n2 = ft_lstnew("toute rose", strlen("toute rose"));
	stock = ft_lst_push_back(&lst, n2);
	if (n2 != stock)
		ERROR();
	if (n2 != n1->next)
		ERROR();
	if (n2 != ft_lst_push_back(NULL, n2))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_WORD_LEN
int		test_word_len(void)
{
	char	str1[] = "Hello World !";
	 char	str2[] = "UnePpetitePMaisoNeTTe";

	if (5 != ft_wordlen(str1, " "))
		ERROR();
	if (13 != ft_wordlen(str1, ""))
		ERROR();
	if (0 != ft_wordlen(NULL, "tiboutchou"))
		ERROR();
	if (2 != ft_wordlen(str2, "eP"))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_PUTSTRTAB
int		test_putstrtab(void)
{
	return (1);
}
#endif

#ifdef TEST_COUNT_WORDS
int		test_count_words(void)
{
	char	str1[] = "Hello World !";
	char	str2[] = "UnePpetitePMaisoNeTTe";

	if (3 != ft_count_words(str1, " "))
		ERROR();
	if (1 != ft_count_words(str1, ""))
		ERROR();
	if (0 != ft_count_words(str1, str1))
		ERROR();
	if (0 != ft_count_words(NULL, "tiboutchou"))
		ERROR();
	if (3 != ft_count_words(str2, "P"))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_IS_IN_STR
int		test_is_in_str(void)
{
	char	str[] = "Hello World !";

	if (0 != ft_is_in_str('H', NULL))
		ERROR();
	if (0 != ft_is_in_str(0, str))
		ERROR();
	if (1 != ft_is_in_str(' ', str))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_STRSPLITSTR
int		test_strsplitstr(void)
{
	char	str[] = "Bonjour mes petites ecrevisses oranges.";
	char	**sp;

	sp = ft_strsplitstr(str, "H KJ");
	if (0 != strcmp(sp[0], "Bonjour"))
		ERROR();
	if (NULL != sp[5])
		ERROR();
	if (0 != strcmp(sp[2], "petites"))
		ERROR();
	sp = ft_strsplitstr(str, "petites");
	if (0 != strcmp(sp[0], "Bonjour m"))
		ERROR();
	sp = ft_strsplitstr(NULL, "petites");
	if (NULL != sp)
		ERROR();
	return (1);
}
#endif

#ifdef TEST_STRSPLIT_TOLST
int		test_strsplit_tolst(void)
{
	char	str[] = "Bonjour mes petites ecrevisses oranges.";
	t_list	*splst;
	splst = ft_strsplit_tolst(str, "H KJ");
	if (0 != strcmp((char *)(splst->content), "Bonjour"))
		ERROR();
	if (NULL != splst->next->next->next->next->next)
		ERROR();
	if (0 != strcmp((char *)(splst->next->next->content), "petites"))
		ERROR();
	splst = ft_strsplit_tolst(str, "petites");
	if (0 != strcmp((char *)(splst->content), "Bonjour m"))
		ERROR();
	splst = ft_strsplit_tolst(NULL, "petites");
	if (NULL != splst)
		ERROR();
	return (1);
}
#endif

#ifdef TEST_PRINT_MEMORY
int		test_print_memory(void)
{
	char	*str;
	int     out;
	int     p[2];
	char    sortie[100];
	char	test[] =
	"00000000: 5361 6c75 7420 6c65 7320 616d 696e 6368 Salut les aminch\n"
	"00000010: 6573 2063 2765 7374 2063 6f6f 6c20 7368 es c!est cool sh\n"
	"00000020: 6f77 206d 656d 206f 6e20 6661 6974 2064 ow mem on fait d\n"
	"00000030: 6520 7472 7563 2074 6572 7269 626c 6500 e truc terrible.\n"
	"00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f ...............";

	str = ft_strdup("Salut les aminches c'est cool"
	" show mem on fait de truc terrible.\01\02\03\04\05\06\07\08\09\14\15\27\127");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	ft_print_memory(test, 79);
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, test))
	{
		dup2(out, 1);
		ERROR();
	}
	if (0 != strcmp("Coucou",ft_print_memory("Coucou", 8)))
		ERROR();
	dup2(out, 1);
	return (1);
}
#endif

#ifdef TEST_ITOABASE
int		test_itoabase(void)
{
	if (0 != strcmp("10", ft_itoabase(2 , 2)))
		ERROR();
	if (NULL != ft_itoabase(2 , 1))
		ERROR();
	if (NULL != ft_itoabase(2 , 70))
		ERROR();
	if (0 != strcmp("0", ft_itoabase(0 , 50)))
		ERROR();
	if (0 != strcmp("-2147483648", ft_itoabase(-2147483648, 10)))
		ERROR();
	if (0 != strcmp("100", ft_itoabase(256, 16)))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_CONVERT_BASE
int		test_convert_base(void)
{
	if (0 != strcmp("11111111", ft_convert_base("255", "0123456789", "01")))
		ERROR();
	if (NULL != ft_convert_base(NULL, "0123456789", "01"))
		ERROR();
	if (NULL != ft_convert_base("255", NULL, "01"))
		ERROR();
	if (NULL != ft_convert_base("255", "0123456789", NULL))
		ERROR();
	if (NULL != ft_convert_base("255", "0123456789", "0"))
		ERROR();
	if (NULL != ft_convert_base("255", "0123456789", "001245"))
		ERROR();
	if (0 != strcmp("185", ft_convert_base("185", "0123456789", "0123456789")))
		ERROR();
	if (0 != strcmp("B9", ft_convert_base("185", "0123456789", "0123456789ABCDEF")))
		ERROR();
	if (0 != strcmp("53", ft_convert_base("185", "0123456789", "ABCDEF0123456789")))
		ERROR();
	if (0 != strcmp("b9", ft_convert_base("185", "0123456789", "0123456789abcdef")))
		ERROR();
	printf("Le truc de batar : %s\n", ft_convert_base("Vincent", "iUyVenNtTCc", "01"));
	if (0 != strcmp("\126A", ft_convert_base("2", "0123456789", "A\126")))
		ERROR();
	return (1);
}
#endif

#ifdef TEST_PRINT_LIST
	ADD_TEST(print_list);
#endif

#ifdef TEST_STRLCPY
int		test_strlcpy(void)
{
	char	str1[] = "Langouste des mères.\0 arides";
	char	str2[] = "Ecrevisse toute rose";
	char	s1[] = "Langouste des mères.\0 arides";

	if (strlcpy(str1, str2, 10) != ft_strlcpy(s1, str2, 10))
	 	ERROR();
	if (0 != strcmp(str1, s1))
		ERROR();
	if (strlcpy(str1, str2 + 5, 20) != ft_strlcpy(s1, str2 + 5, 20))
		 ERROR();
	if (strlcpy(str1, str2 + 15, 0) != ft_strlcpy(s1, str2 + 15, 0))
 		ERROR();
	if (strlcpy(str1 + 20, str2 + 8, 10) != ft_strlcpy(s1 + 20, str2 + 8, 10))
 	 	ERROR();
	return (1);
}
#endif

#ifdef TEST_ATOI2
int		test_atoi2(void)
{
	if (0 != ft_atoi2(""))
		ERROR();
	if (0 != ft_atoi2(NULL))
		ERROR();
	if (-2147483648 != ft_atoi2(" \f\f\t\n      -2147483648"))
		ERROR();
	if (-2147483648 != ft_atoi2(" \f\f\t\n      -2147483648784"))
		ERROR();
	if (-2147483648 != ft_atoi2(" \f\f\t\n      -2147483648784"))
		ERROR();
	if (2147483647 != ft_atoi2(" \f\f\t\n      +21474836479984"))
		ERROR();
	if (314748364 != ft_atoi2(" \f\f\t\n      +31474836479984"))
		ERROR();
	return (1);
}
#endif
