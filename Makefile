SRC		=	main.cpp\

OBJ		=	$(SRC:.cpp = .o)

MODULE	=	-lsfml-window\
			-lsfml-system\
			-lsfml-graphics\

DATA 	=	data/GamesWindow.cpp\
			data/GamesWindowControl.cpp\
			data/GamesWindowCollide.cpp\
			data/GamesWindowDraw.cpp\
			data/GamesWindowMap.cpp\
			\
			data/Monster.cpp\
			\
			data/Joueur.cpp\
			\
			data/Wall.cpp\
			\
			data/Ground.cpp\
			\
			data/Heart.cpp\
			\
			data/MapGenerator.cpp\
			\
			data/Sword.cpp\
			\

NAME	=	main

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null