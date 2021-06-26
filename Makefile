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

SRC		=	main.cpp\

OBJ		=	$(SRC:.cpp = .o)

MODULE	=	-lsfml-window\
			-lsfml-system\
			-lsfml-graphics\

DATA	=	src/Chest/Accessor.cpp\
			src/Chest/Constructor.cpp\
			src/Chest/Generate.cpp\
			src/Chest/Sprite.cpp\
			\
			src/Gain/Accessor.cpp\
			src/Gain/Chose.cpp\
			src/Gain/Constructor.cpp\
			src/Gain/Sprite.cpp\
			\
			src/Game/Accessor.cpp\
			src/Game/Collide.cpp\
			src/Game/Constructor.cpp\
			src/Game/Control.cpp\
			src/Game/Draw.cpp\
			src/Game/Map.cpp\
			src/Game/Monster.cpp\
			src/Game/Sword.cpp\
			\
			src/GamesWindow/Accessor.cpp\
			src/GamesWindow/Constructor.cpp\
			src/GamesWindow/Control.cpp\
			src/GamesWindow/Draw.cpp\
			src/GamesWindow/Window.cpp\
			\
			src/Ground/Accessor.cpp\
			src/Ground/Constructor.cpp\
			src/Ground/Position.cpp\
			src/Ground/Sprite.cpp\
			\
			src/Heart/Accessor.cpp\
			src/Heart/Constructor.cpp\
			src/Heart/LifeBar.cpp\
			src/Heart/Sprite.cpp\
			\
			src/Joueur/AccessorLife.cpp\
			src/Joueur/AccessorOrientation.cpp\
			src/Joueur/AccessorPosition.cpp\
			src/Joueur/AccessorRubis.cpp\
			src/Joueur/Animation.cpp\
			src/Joueur/Constructor.cpp\
			src/Joueur/Life.cpp\
			src/Joueur/Move.cpp\
			src/Joueur/Orientation.cpp\
			src/Joueur/Rubis.cpp\
			src/Joueur/Sprite.cpp\
			\
			src/MakeSprite/MakeSprite.cpp\
			\
			src/MapGenerator/Accessor.cpp\
			src/MapGenerator/Chest.cpp\
			src/MapGenerator/Constructor.cpp\
			src/MapGenerator/CreateMap.cpp\
			\
			src/Monster/Monster.cpp\
			src/Monster/MonsterAccessor.cpp\
			src/Monster/MonsterPrivatePatern.cpp\
			src/Monster/MonsterPrivateSprite.cpp\
			src/Monster/MonsterPublicGain.cpp\
			src/Monster/MonsterPublicLife.cpp\
			src/Monster/MonsterPublicMoove.cpp\
			\
			src/Rubis/Rubis.cpp\
			src/Rubis/RubisAccessor.cpp\
			src/Rubis/RubisPrivateText.cpp\
			src/Rubis/RubisPublicUpdate.cpp\
			\
			src/Sword/Sword.cpp\
			src/Sword/SwordAccessor.cpp\
			src/Sword/SwordPrivateAnimation.cpp\
			src/Sword/SwordPrivateSprite.cpp\
			src/Sword/SwordPublicAnimation.cpp\
			src/Sword/SwordPublicOrientation.cpp\
			src/Sword/SwordPublicPower.cpp\
			\
			src/Wall/Wall.cpp\
			src/Wall/WallAccessor.cpp\
			src/Wall/WallPrivateSprite.cpp\
			src/Wall/WallPublicPosition.cpp\
			\

NAME	=	ZeldaLike.o

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))