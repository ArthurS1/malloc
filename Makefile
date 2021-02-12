##
## EPITECH PROJECT, 2021
## Makefile for the my_malloc project
## File description:
## Makefile
##

#QUICKSTART GUIDE:########################################################################
#Objects variable contain .o file and output variable contains the output name we want\  #
#therefore, liboutput is 'libmy.a' and libobjects features 'lib/my_putchar.o'\           #
#Those objects are contained within lib.mk, test.mk and src.mk respectively for\         #
#modularity purposes.                                                                    #
##########################################################################################

srcobjects	=	src/malloc.o	src/free.o	src/realloc.o	src/support.o

##########################################################################################

#COMPILATION OPTIONS : add flags or change compiler
##########################################################################################

NAME	=	libmy_malloc.so

CC	=	gcc

CFLAGS	+=	-Wall		\
			-Wextra		\
			-iquote ./include	\

#IMPLICIT RULES
##########################################################################################

%.o:	%.c
	$(CC) -fpic -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo -e "\e[0mCompiling : $@ \e[92mOK\e[0m"

##########################################################################################

all:	$(NAME)

##########################################################################################

$(NAME):	$(srcobjects)
	$(CC) -shared $(CFLAGS) $(srcobjects) -o $(NAME)
	@echo -e "\e[0mLinking lib : \e[92mOK\e[0m"

##########################################################################################

fclean:	clean
	@rm -f $(srcmain)	$(srcobjects)
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
