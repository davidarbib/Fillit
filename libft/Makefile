# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 09:47:08 by pitriche          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/02/22 14:35:26 by pitriche         ###   ########.fr        #
=======
#    Updated: 2019/02/21 18:09:24 by darbib           ###   ########.fr        #
>>>>>>> aa4f8250e5a01d2da8917577cfa2b72f1e3f455f
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_strlen.c ft_itoa.c \
ft_putendl.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_putendl_fd.c \
ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_memchr.c ft_memcmp.c \
ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_atoi.c ft_strncat.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strncmp.c ft_strnstr.c \
ft_strcmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_tolower.c ft_toupper.c ft_memmove.c ft_strnew.c ft_memalloc.c ft_memdel.c \
ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_isspace.c \
ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c ft_strndup.c ft_print_words_tables.c ft_strncpy_bw.c ft_memdup.c \
ft_lstnew_empty.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo 'Libft linking successful'

$(NAME): $(OBJ)
	@echo '✔'
	@echo 'Libft compiling successful'
	@ar rc $@ $^
	@ranlib $@

%.o: %.c
	@$(CC) $(FLAGS) -c $^
	@echo -n '.'
 
clean:
	@rm -f $(OBJ)
	@echo 'Libft objects deleted'

fclean: clean
	@rm -f $(NAME)
	@echo 'libft.a deleted'

re: fclean all

.PHONY: all, clean, fclean, re
