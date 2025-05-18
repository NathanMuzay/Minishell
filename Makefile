##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Iinclude
LDFLAGS = -lm
SRC_LIB = $(wildcard lib/my/*.c)
OBJ_LIB = $(SRC_LIB:.c=.o)
SRC_PROG = $(shell find src -name '*.c')
OBJ_PROG = $(SRC_PROG:.c=.o)
NAME = 42sh

all: $(NAME)

libmy.a: $(OBJ_LIB)
	ar rcs libmy.a $(OBJ_LIB)

$(NAME): libmy.a $(OBJ_PROG)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PROG) -L. -lmy $(LDFLAGS)

clean:
	rm -f $(OBJ_LIB) $(OBJ_PROG)

fclean: clean
	rm -f libmy.a $(NAME)

re: fclean all
