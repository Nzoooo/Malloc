##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	src/malloc.c	\
			src/free.c		\
			src/calloc.c	\
			src/realloc.c	\
			src/reallocarray.c	\
			src/node.c

MAIN	= 	main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -fpic -I./include

CC		=	gcc

RM		=	rm

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) -f $(OBJ)

fclean:	clean
		$(RM) -f $(NAME)

re:		fclean all

.PHONY:	fclean clean re all