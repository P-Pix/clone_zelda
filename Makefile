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

DATA 	=	src/Chest/Chest.cpp\
			src/Chest/ChestAccessor.cpp\
			src/Chest/ChestPrivateSprite.cpp\
			src/Chest/ChestPublicGenerate.cpp\
			\
			src/Gain/Gain.cpp\
			src/Gain/GainAccessor.cpp\
			src/Gain/GainPrivateSprite.cpp\
			src/Gain/GainPublicChose.cpp\
			\
			src/Game/Game.cpp\
			src/Game/GameAccessor.cpp\
			src/Game/GamePrivateCollide.cpp\
			src/Game/GamePrivateDraw.cpp\
			src/Game/GamePrivateMap.cpp\
			src/Game/GamePrivateMonster.cpp\
			src/Game/GamePrivateSword.cpp\
			src/Game/GamePublic.cpp\
			\
			src/GamesWindow/GamesWindow.cpp\
			src/GamesWindow/GamesWindowAccessor.cpp\
			src/GamesWindow/GamesWindowPrivateControl.cpp\
			src/GamesWindow/GamesWindowPrivateDraw.cpp\
			src/GamesWindow/GamesWindowPublicWindow.cpp\
			\
			src/Ground/Ground.cpp\
			src/Ground/GroundPrivateSprite.cpp\
			src/Ground/GroundAccessor.cpp\
			src/Ground/GroundPublicPosition.cpp\
			\
			src/Heart/Heart.cpp\
			src/Heart/HeartPrivateSprite.cpp\
			src/Heart/HeartAccessorSprite.cpp\
			src/Heart/HeartPublicLifeBar.cpp\
			\
			src/Joueur/Joueur.cpp\
			src/Joueur/JoueurAccessorLife.cpp\
			src/Joueur/JoueurAccessorOrientation.cpp\
			src/Joueur/JoueurAccessorPosition.cpp\
			src/Joueur/JoueurAccessorRubis.cpp\
			src/Joueur/JoueurPrivateMove.cpp\
			src/Joueur/JoueurPrivateSprite.cpp\
			src/Joueur/JoueurPublicAnimation.cpp\
			src/Joueur/JoueurPublicLife.cpp\
			src/Joueur/JoueurPublicMove.cpp\
			src/Joueur/JoueurPublicRubis.cpp\
			src/Joueur/JoueurPublicSwitchOrientation.cpp\
			\
			src/MakeSprite/MakeSprite.cpp\
			\
			src/MapGenerator/MapGenerator.cpp\
			src/MapGenerator/MapGeneratorAccessorElement.cpp\
			src/MapGenerator/MapGeneratorAccessorList.cpp\
			src/MapGenerator/MapGeneratorPublicChest.cpp\
			src/MapGenerator/MapGeneratorPublicCreateMap.cpp\
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