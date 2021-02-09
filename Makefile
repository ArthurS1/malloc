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

srcobjects	=	src/malloc.o	src/free.o

##########################################################################################

#COMPILATION OPTIONS : add flags or change compiler
##########################################################################################

NAME	=	libmy_malloc.so

CC	=	gcc

#Note that the --coverage flag will be added only for testing and -ggdb for debuging
CFLAGS	+=	-Wall		\
			-Wextra		\
			-shared		\

LDLIBS	+=

#IMPLICIT RULES
##########################################################################################

%.o:	%.c
	@$(CXX) -fpic -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo -e "\e[0mCompiling : $@ \e[92mOK\e[0m"

##########################################################################################

all:	$(NAME)

##########################################################################################

$(NAME):	$(srcobjects)
	@$(CXX) $(CFLAGS) -o $(NAME) $(srcobjects) $(LDFLAGS) $(LDLIBS)
	@echo -e "\e[0mLinking sources : \e[92mOK\e[0m"

##########################################################################################

debug:	CFLAGS += -ggdb
debug:	fclean	$(NAME)
	@gdb ./$(NAME)

##########################################################################################

fclean:	clean
	@rm -f $(srcmain)	$(srcobjects)
	@echo -e "\e[91mRemoving object files : \e[0mOK"

##########################################################################################

clean:
	@rm -f	$(NAME)
	@echo -e "\e[91mRemoving binary files : \e[0mOK"

##########################################################################################

re:	fclean	all