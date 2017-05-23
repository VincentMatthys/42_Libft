# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmatthys <vmatthys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 15:51:42 by vmatthys          #+#    #+#              #
#    Updated: 2016/12/06 23:14:36 by vmatthys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RELATIVE = .
OBJ_PATH = .
SRC_NAME =	ft_atoi.c \
			ft_atoi2.c \
			ft_bzero.c \
			ft_convert_base.c \
			ft_count_words.c \
			ft_is_in_str.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoabase.c \
			ft_lst_push_back.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstfold.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_print_memory.c \
			ft_printlist.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstrtab.c \
			ft_str_initialized.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strsplitstr.c \
			ft_strsplit_tolst.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wordlen.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Weverything
INC = .
LIBFT_PATH = .
CPPFLAGS = -I$(INC)
NAME = $(LIBFT_PATH)/libft.a

.PHONY: clean fclean all re

all : $(NAME)


$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)%.c $(INC)libft.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
