# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 21:25:30 by darbib            #+#    #+#              #
#    Updated: 2019/02/22 14:35:08 by pitriche         ###   ########.fr        #
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

.PHONY: all clean fclean re

all : $(EXE)
	@echo 'Linking successful, ready to run'

$(EXE): $(LIBS) $(OBJ)
	@echo '✔'
	@echo 'Compiling successful'
	@$(CC) $(LFLAGS) $(OBJ) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) $^
	@echo -n '.'

$(LIBS) :
	@make -C libft

clean:
	@rm -f $(OBJ)
	@echo "Fillit objects deleted"

fclean : clean
	@rm -f $(EXE)
	@make -C libft fclean 
	@echo 'Fillit deleted'

re : fclean all

