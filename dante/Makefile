##
## Makefile for Makefile in umery_h/rendu/PSU_2015_minishell1
##
## Made by Henry Fumery (fumery_h)
## Login   <fumery_h@epitech.eu>
##
## Started on  Sun Jan 17 23:54:41 2016 Henry Fumery (fumery_h)
## Last update Sun Jan 17 23:54:41 2016 Henry Fumery (fumery_h)
##
SAMPLE=	mazes_samples/testi1.txt
GENERATOR_DIR=  ./generator/srcs/
GENERATOR_SRCS=	$(GENERATOR_DIR)dante_lab.c 		\
	$(GENERATOR_DIR)mal_funct.c		\
	$(GENERATOR_DIR)init_lab.c		\
	$(GENERATOR_DIR)free_funct.c 		\
	$(GENERATOR_DIR)save.c			\
	$(GENERATOR_DIR)check_funct.c 		\
	$(GENERATOR_DIR)parf_lab_funct.c 	\
	$(GENERATOR_DIR)impa_lab_funct.c 	\

SOLVER_DIR=	./width/srcs/
SOLVER_SRCS=	$(SOLVER_DIR)main.c 		\
	$(SOLVER_DIR)mal_funct.c		\
	$(SOLVER_DIR)get_lab.c		\
	$(SOLVER_DIR)check_funct.c 		\
	$(SOLVER_DIR)save.c 			\
	$(SOLVER_DIR)draw_path.c 		\
	$(SOLVER_DIR)free_funct.c		\

CC= 	gcc
GENERATOR_OBJ=	$(GENERATOR_SRCS:.c=.o)
SOLVER_OBJ=	$(SOLVER_SRCS:.c=.o)

GENERATOR_NAME=	./generator/generator
SOLVER_NAME=	./width/solver

all:	$(GENERATOR_NAME) $(SOLVER_NAME)

$(GENERATOR_NAME):	$(GENERATOR_OBJ)
		$(CC) -o $(GENERATOR_NAME) $(GENERATOR_OBJ)

$(SOLVER_NAME):	$(SOLVER_OBJ)
		$(CC) -o $(SOLVER_NAME) $(SOLVER_OBJ)

clean:
	@rm -f $(GENERATOR_OBJ) $(SOLVER_OBJ)

fclean: clean
	@rm -f $(GENERATOR_NAME) $(SOLVER_NAME)

re:	fclean all

run_test:
	@$(SOLVER_NAME) $(SAMPLE)

run_test_valgrind:
	@valgrind $(SOLVER_NAME) $(SAMPLE)

test: all run_test fclean

test_valgrind: all run_test_valgrind fclean