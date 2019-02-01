# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 21:25:30 by darbib            #+#    #+#              #
#    Updated: 2019/02/01 20:43:57 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
EXE = fillit
LIBS = libft/libft.a
CFLAGS = -c -Wall -Werror -Wextra
LFLAGS = -o $(EXE) -Wall -Werror -Wextra
ALL_C = main.c
ALL_O = main.o

all : $(EXE)

$(EXE): $(ALL_O) $(LIBS)
	$(CC) $(LFLAGS) $(ALL_O) $(LIBS)

$(ALL_O): $(ALL_C)
	$(CC) $(CFLAGS) $(ALL_C)

$(LIBS) :
	make -C libft

clean:
	rm -f $(ALL_O)

fclean : clean
	rm -f $(EXE)
	make -C libft fclean 

re : fclean all
