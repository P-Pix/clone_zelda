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

DATA1	=	FirstVersion/src/main.cpp\
			FirstVersion/src/Chest/*.cpp\
			FirstVersion/src/Gain/*.cpp\
			FirstVersion/src/Game/*.cpp\
			FirstVersion/src/GamesWindow/*.cpp\
			FirstVersion/src/Ground/*.cpp\
			FirstVersion/src/Heart/*.cpp\
			FirstVersion/src/Joueur/*.cpp\
			FirstVersion/src/MakeSprite/*.cpp\
			FirstVersion/src/MapGenerator/*.cpp\
			FirstVersion/src/Monster/*.cpp\
			FirstVersion/src/Rubis/*.cpp\
			FirstVersion/src/Sword/*.cpp\
			FirstVersion/src/Wall/*.cpp\

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