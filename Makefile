SRC		=	main.cpp\

OBJ		=	$(SRC:.cpp = .o)

MODULE	=	-lsfml-window\
			-lsfml-system\
			-lsfml-graphics\

DATA 	=	data/GamesWindow/GamesWindow.cpp\
			data/GamesWindow/GamesWindowControl.cpp\
			data/GamesWindow/GamesWindowCollide.cpp\
			data/GamesWindow/GamesWindowDraw.cpp\
			data/GamesWindow/GamesWindowMap.cpp\
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