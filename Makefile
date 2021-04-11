SRC = main.cpp\

OBJ = $(SRC:.cpp = .o)

FLAGS = -lsfml-window -lsfml-system -lsfml-graphics

NAME = main

$(NAME): $(OBJ)
	@(g++ -o $(NAME) $(OBJ) $(FLAGS)) > /dev/null

all: $(NAME)