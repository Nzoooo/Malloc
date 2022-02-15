##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	/src/malloc.c	\
			/src/free.c		\
			/src/calloc.c	\
			/src/realloc.c	\
			/src/reallocarray.c	\
			/src/node.c

MAIN	= 	main.c

OBJ		=	$(SRC:.c=.o)
MAINOBJ	=	$(MAIN:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./include

LDFLAGS	=	-ldl

CC		=	gcc

RM		=	rm

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -c -fpic $(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ)

clean:
		$(RM) -f $(OBJ)

fclean:	clean
		$(RM) -f $(NAME)

re:		fclean all

c:		$(MAINOBJ)
		$(CC) -o a.out $(MAINOBJ) $(LDFLAGS)

.PHONY:	fclean clean re all