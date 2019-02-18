# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 21:25:30 by darbib            #+#    #+#              #
#    Updated: 2019/02/14 17:59:24 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
LFLAGS = -o $(EXE) -Wall -Werror -Wextra

EXE = fillit
LIBS = libft/libft.a

SRC = main.c parsing.c placing.c utils.c
OBJ = $(SRC:.c=.o)

# **************************************************************************** #

all : $(EXE)

$(EXE): $(OBJ) $(LIBS)
	$(CC) $(LFLAGS) $(OBJ) $(LIBS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

$(LIBS) :
	make -C libft

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXE)
	make -C libft fclean 

re : fclean all
