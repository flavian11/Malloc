##
## Makefile for  in /home/flav/epitech/CPE/rush/CPE_rush4stek_2016/m
## 
## Made by flav
## Login   <flavian.feugueur@epitech.eu>
## 
## Started on  Sat Jun  3 18:35:38 2017 flav
## Last update Mon Jun 12 13:33:26 2017 
##
ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"


CC	=	gcc

RM	=	rm -f

SRC	=	src/

READ	=	$(SRC)read/

SRCS	=	$(SRC)malloc.c \
		$(SRC)calloc.c \
		$(SRC)free.c

OBJ	=	$(SRCS:.c=.o)

NAME	=	my_malloc.so

CFLAGS	+=	-fPIC \
		-I ./include -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -shared

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.c=.c~)
	$(RM) $(SRCS:.c=.c#)

fclean: clean
	$(RM) $(NAME)

re: fclean all

flav: re
	make clean

.c.o:
		@gcc $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
