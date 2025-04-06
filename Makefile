##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##

CC = gcc
AR = ar rcs
CFLAGS = -Iinclude -I./csfml/include
SRC_LIB = $(wildcard lib/my/*.c)
OBJ_LIB = $(SRC_LIB:.c=.o)
MY_H = my.h
NAME = mysh
SRC_PROG = $(shell find . -type f -name "*.c")
OBJ_PROG = $(SRC_PROG:.c=.o)

all: $(NAME)

libmy.a: $(OBJ_LIB)
	$(AR) libmy.a $(OBJ_LIB)

all: libmy.a $(NAME)

$(NAME): libmy.a $(OBJ_PROG)
	$(CC) -o $(NAME) $(OBJ_PROG) -L. -lmy $(LDFLAGS) -lm

clean:
	rm -f $(OBJ_LIB) $(OBJ_PROG)

fclean: clean
	rm -f libmy.a $(NAME)

re: fclean all clean
