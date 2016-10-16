##
## Makefile for malloc in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_malloc
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Fri Feb 12 19:18:58 2016 
## Last update Sun Oct 16 22:33:26 2016 
##

CC		=	gcc

CFLAGS		=	-I./include -O2 -pipe -shared -fPIC

NAME		=	libmy_malloc.so

NAME_STAT	=	malloc_stat.txt

SRC		=	malloc.c		\
		 	realloc.c		\
		 	free.c			\
			calloc.c		\
			show_alloc_mem.c	\
			config.c		\
			stat.c			\
			stat_editors.c		\
			stat_printer.c		\
			fd_display.c		\
			algorithm.c		\

OBJ             =       $(addprefix src/, $(SRC:.c=.o))

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_STAT)

re: fclean all
