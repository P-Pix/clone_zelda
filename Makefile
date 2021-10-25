####
### @file Makefile
### @author Guillaume LEMONNIER
### @brief 
### @version 0.1
### @date 2021-05-31
### 
### @copyright Copyright (c) 2021
### 
####

SRC		=	src/main.cpp\

OBJ		=	$(SRC:.cpp = .o)

MODULE	=	-lsfml-window\
			-lsfml-system\
			-lsfml-graphics\

DATA	=	src/Chest/*.cpp\
			src/Gain/*.cpp\
			src/Game/*.cpp\
			src/GamesWindow/*.cpp\
			src/Ground/*.cpp\
			src/Heart/*.cpp\
			src/Joueur/*.cpp\
			src/MakeSprite/*.cpp\
			src/MapGenerator/*.cpp\
			src/Monster/*.cpp\
			src/Rubis/*.cpp\
			src/Sword/*.cpp\
			src/Wall/*.cpp\

NAME	=	ZeldaLike.obj

VERSION	=	-std=c++2a\

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE) $(VERSION)) > /dev/null

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE) $(VERSION)) > /dev/null

run:
	@(./$(NAME))