##
## Makefile for BSQ in /home/robin/rendu/prog_elem/CPE_2015_BSQ
## 
## Made by robin
## Login   <robin@epitech.net>
## 
## Started on  Mon Dec 14 14:30:17 2015 robin
## Last update Sun Feb 21 13:35:50 2016 Voyevoda
##

CC	=	gcc

SRC	=	main.c			\
		print_game_board.c	\
		get_next_line.c		\
		my_getnumbr.c		\
		my_put_nbr.c		\
		fct.c			\
		malloc.c

CFLAGS	=	 -Wall -Wextra -W -ansi -pedantic 

RM	=	rm -f

NAME	=	allum1

OBJ	=	$(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re	: fclean all

.phony : all clean fclean re
