##
## Makefile for Makefile in umery_h/rendu/PSU_2015_minishell1
##
## Made by Henry Fumery (fumery_h)
## Login   <fumery_h@epitech.eu>
##
## Started on  Sun Jan 17 23:54:41 2016 Henry Fumery (fumery_h)
## Last update Sun Jan 17 23:54:41 2016 Henry Fumery (fumery_h)
##
DIR1=  ./generator/srcs/
SRCS1=	$(DIR1)dante_lab.c 		\
	$(DIR1)mal_funct.c		\
	$(DIR1)init_lab.c		\
	$(DIR1)free_funct.c 		\
	$(DIR1)save.c			\
	$(DIR1)check_funct.c 		\
	$(DIR1)parf_lab_funct.c 	\
	$(DIR1)impa_lab_funct.c 	\

DIR2=	./width/srcs/
SRCS2=	$(DIR2)resolve.c 		\
	$(DIR2)mal_funct.c		\
	$(DIR2)get_lab.c		\
	$(DIR2)check_funct.c 		\
	$(DIR2)save.c 			\
	$(DIR2)draw_path.c 		\
	$(DIR2)free_funct.c		\

CC= 	gcc
OBJ1=	$(SRCS1:.c=.o)
OBJ2=	$(SRCS2:.c=.o)

NAME1=	./generator/generator
NAME2=	./width/solver

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		$(CC) -o $(NAME1) $(OBJ1)

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2)

clean:
	@rm -f $(OBJ1) $(OBJ2)
fclean: clean
	@rm -f $(NAME1) $(NAME2)
re:	fclean all
