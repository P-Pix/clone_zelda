SRC = main.cpp\

OBJ = $(SRC:.cpp = .o)

FLAGS = -lsfml-window -lsfml-system -lsfml-graphics

NAME = main

#$(NAME): $(OBJ)
#	@(valgrind g++ -o $(NAME) $(OBJ) $(FLAGS)) > /dev/null
#
#all: $(NAME)

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(FLAGS)) > /dev/null

cpp:
	@(g++ -o $(NAME) $(OBJ) $(FLAGS)) > /dev/null