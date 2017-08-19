/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:33:20 by tbeauman          #+#    #+#             */
/*   Updated: 2016/11/13 22:16:37 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Les tests definis ici seront effectues
#define TEST_LSTNEW
#define TEST_LSTDELONE
#define TEST_LSTDEL
#define TEST_LSTADD
#define TEST_LSTITER
#define TEST_LSTMAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include "libft.h"

int		test_lstnew(void);
int		test_lstdelone(void);
int		test_lstdel(void);
int		test_lstadd(void);
int		test_lstmap(void);
int     test_lstiter(void);

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


#ifdef TEST_LSTNEW
    ADD_TEST(lstnew);
#endif
#ifdef TEST_LSTDELONE
    ADD_TEST(lstdelone);
#endif
#ifdef TEST_LSTDEL
    ADD_TEST(lstdel);
#endif
#ifdef TEST_LSTADD
    ADD_TEST(lstadd);
#endif
#ifdef TEST_LSTITER
    ADD_TEST(lstiter);
#endif
#ifdef TEST_LSTMAP
    ADD_TEST(lstmap);
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

#ifdef TEST_LSTNEW
int		test_lstnew(void)
{
    t_list	*lst;

    lst = ft_lstnew("abcdefghi", 10);
    if (0 != memcmp(lst->content, "abcdefghi", 10))
        ERROR();
    free(lst);

    lst = ft_lstnew("abc\0def", 8);
    if (0 != memcmp(lst->content, "abc\0def", 8))
        ERROR();
    free(lst);

    lst = ft_lstnew(NULL, 5);
    if (NULL != lst->content)
        ERROR();
    if (0 != lst->content_size)
        ERROR();
    free(lst);

    return (1);
}
#endif

#ifdef TEST_LSTDELONE
void    fake_del(void *content, size_t content_size);
void    fake_del(void *content, size_t content_size)
{
    (*(int *)content) = 1000 + (int)content_size;
}

int     test_lstdelone(void)
{
    t_list  *maillon;
    t_list  *pmaillon;
    void    *maillon_content;
    int pid;
    int status;


    maillon = ft_lstnew("abcdefg", 8);
    pmaillon = maillon;
    maillon->next = (void*)1; // Fait volontairement planter si on libere next
    maillon_content = maillon->content;

    ft_lstdelone(&pmaillon, fake_del);
    if (1008 != *(int *)maillon_content)
        ERROR();

    if (NULL != pmaillon)
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
        free(maillon);
        exit(0);
    }

    return (1);
}
#endif

#ifdef TEST_LSTDEL
void    fake_del2(void *content, size_t content_size);
void    fake_del2(void *content, size_t content_size)
{
    (*(int *)content) = 1000 + (int)content_size;
}

int     test_lstdel(void)
{
    int     pid;
    int     status;
    t_list  *lst;
    t_list  *dernier_maillon;
    lst = ft_lstnew("abcdefg", 8);
    lst->next = ft_lstnew("abc", 4);
    lst->next->next = ft_lstnew("ab", 3);
    dernier_maillon = lst->next->next;

    ft_lstdel(&lst->next, fake_del2);

    if (NULL != lst->next)
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
        free(dernier_maillon);
        exit(0);
    }

    return (1);
}
#endif

#ifdef TEST_LSTADD
int		test_lstadd(void)
{
    t_list	*lst;
    t_list  *maillon;

    maillon = malloc(sizeof(t_list));
    lst = ft_lstnew("abc", 4);

    maillon->content_size = 5;
    maillon->content = malloc(5);
    strcpy((char*)maillon->content, "defg");
    ft_lstadd(&lst, maillon);

    if (0 != memcmp(lst->next->content, "abc", 4))
        ERROR();

    if (4 != lst->next->content_size)
        ERROR();

    if (5 != maillon->content_size)
   		ERROR();

    if (0 != memcmp(lst->content, "defg", 5))
        ERROR();

    if (maillon != lst)
        ERROR();

    return (1);
}
#endif

#ifdef TEST_LSTITER
void    f1(t_list *elem);
void    f1(t_list *elem)
{
    elem->content_size = 123;
}

int     test_lstiter(void)
{
    t_list  elem1;
    t_list  elem2;
    t_list  elem3;
    t_list  elem4;

    elem1.next = &elem2;
    elem2.next = &elem3;
    elem3.next = &elem4;
    elem4.next = NULL;

    ft_lstiter(&elem1, f1);

    if (123 != elem1.content_size)
        ERROR();
    if (123 != elem4.content_size)
        ERROR();

    return (1);
}
#endif

#ifdef TEST_LSTMAP
t_list    *f2(t_list *elem);
t_list    *f2(t_list *elem)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    new->content_size = elem->content_size + 10;
    new->content = malloc(elem->content_size + 10);

    return (new);
}

int     test_lstmap(void)
{
    t_list  elem1;
    t_list  elem2;
    t_list  elem3;
    t_list  elem4;
    t_list  *result;

    elem1.next = &elem2;
    elem2.next = &elem3;
    elem3.next = &elem4;
    elem4.next = NULL;


    elem1.content_size = 5;
    elem2.content_size = 6;
    elem3.content_size = 7;
    elem4.content_size = 8;

    elem1.content = malloc(5);
    elem2.content = malloc(6);
    elem3.content = malloc(7);
    elem4.content = malloc(8);

    result = ft_lstmap(&elem1, f2);

    if (15 != result->content_size)
        ERROR();
    if (16 != result->next->content_size)
        ERROR();
    if (17 != result->next->next->content_size)
        ERROR();
    if (18 != result->next->next->next->content_size)
        ERROR();

    return (1);
}
#endif
