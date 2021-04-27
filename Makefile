SRC = 	main.cpp\

OBJ = 	$(SRC:.cpp = .o)

FLAGS = -lsfml-window\
		-lsfml-system\
		-lsfml-graphics\

DATA = 	data/Monster.cpp\
		data/GamesWindow.cpp\
		data/Joueur.cpp\
		data/Wall.cpp\
		data/Ground.cpp\
		data/Heart.cpp\

NAME = 	main

#$(NAME): $(OBJ)
#	@(valgrind g++ -o $(NAME) $(OBJ) $(FLAGS)) > /dev/null
#
#all: $(NAME)

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(FLAGS)) > /dev/null

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(FLAGS)) > /dev/null