##
## EPITECH PROJECT, 2021
## Makefile for the my_malloc project
## File description:
## Makefile
##



SRC	:=	src/malloc.c
SRC += 	src/malloc_misc.c
SRC += 	src/malloc_append.c
SRC	+=	src/free.c
SRC +=	src/realloc.c
SRC +=	src/calloc.c
SRC +=	src/reallocarray.c



#COMPILATION OPTIONS : add flags or change compiler
##########################################################################################

NAME	:=	libmy_malloc.so

CC	:=	gcc

CFLAGS	:=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-iquote ./include

OBJ	=	$(SRC:.c=.o)

#IMPLICIT RULES
##########################################################################################

%.o:	%.c
	@$(CC) -fpic -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo -e "\e[0mCompiling : $@ \e[92mOK\e[0m"

##########################################################################################

all:	$(NAME)

##########################################################################################

$(NAME):	$(OBJ)
	@$(CC) -shared $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -e "\e[0mLinking lib : \e[92mOK\e[0m"

##########################################################################################

fclean:	clean
	@rm -f	$(OBJ)
	@echo -e "\e[91mRemoving object files : \e[0mOK"

##########################################################################################

debug: CFLAGS += -ggdb
debug: re

##########################################################################################

clean:
	@rm -f	$(NAME)
	@echo -e "\e[91mRemoving binary files : \e[0mOK"

##########################################################################################

re:	fclean	all
