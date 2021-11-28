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

MODULE	=	-lsfml-window\
			-lsfml-system\
			-lsfml-graphics\

DATA1	=	src/main.cpp\
			src/Chest/*.cpp\
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

DATA2	=	SecondVersion/src/main.cpp\

NAME	=	ZeldaLike.obj

VERSION	=	-std=c++2a\

val1:
	@(valgrind g++ -o $(NAME) $(DATA1) $(MODULE) $(VERSION)) > /dev/null

cpp1:
	@(g++ -o $(NAME) $(DATA1) $(MODULE) $(VERSION)) > /dev/null

cpp2:
	@(g++ -o $(NAME) $(DATA2) $(MODULE) $(VERSION)) > /dev/null

run:
	@(./$(NAME))