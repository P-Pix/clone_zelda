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
			data/Monster/Monster.cpp\
			\
			data/Joueur/Joueur.cpp\
			\
			data/Wall/Wall.cpp\
			\
			data/Ground/Ground.cpp\
			\
			data/Heart/Heart.cpp\
			\
			data/MapGenerator/MapGenerator.cpp\
			\
			data/Sword/Sword.cpp\
			\

NAME	=	main

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null