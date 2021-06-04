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

DATA 	=	data/Chest/Chest.cpp\
			data/Chest/ChestAccessor.cpp\
			data/Chest/ChestPrivateSprite.cpp\
			data/Chest/ChestPublicGenerate.cpp\
			\
			data/Gain/Gain.cpp\
			data/Gain/GainAccessor.cpp\
			data/Gain/GainPrivateSprite.cpp\
			data/Gain/GainPublicChose.cpp\
			\
			data/Game/Game.cpp\
			data/Game/GameAccessor.cpp\
			data/Game/GamePrivateCollide.cpp\
			data/Game/GamePrivateDraw.cpp\
			data/Game/GamePrivateMap.cpp\
			data/Game/GamePrivateMonster.cpp\
			data/Game/GamePrivateSword.cpp\
			data/Game/GamePublic.cpp\
			\
			data/GamesWindow/GamesWindow.cpp\
			data/GamesWindow/GamesWindowAccessor.cpp\
			data/GamesWindow/GamesWindowPrivateControl.cpp\
			data/GamesWindow/GamesWindowPrivateDraw.cpp\
			data/GamesWindow/GamesWindowPublicWindow.cpp\
			\
			data/Ground/Ground.cpp\
			data/Ground/GroundPrivateSprite.cpp\
			data/Ground/GroundAccessor.cpp\
			data/Ground/GroundPublicPosition.cpp\
			\
			data/Heart/Heart.cpp\
			data/Heart/HeartPrivateSprite.cpp\
			data/Heart/HeartAccessorSprite.cpp\
			data/Heart/HeartPublicLifeBar.cpp\
			\
			data/Joueur/Joueur.cpp\
			data/Joueur/JoueurAccessorLife.cpp\
			data/Joueur/JoueurAccessorOrientation.cpp\
			data/Joueur/JoueurAccessorPosition.cpp\
			data/Joueur/JoueurAccessorRubis.cpp\
			data/Joueur/JoueurPrivateMove.cpp\
			data/Joueur/JoueurPrivateSprite.cpp\
			data/Joueur/JoueurPublicAnimation.cpp\
			data/Joueur/JoueurPublicLife.cpp\
			data/Joueur/JoueurPublicMove.cpp\
			data/Joueur/JoueurPublicRubis.cpp\
			data/Joueur/JoueurPublicSwitchOrientation.cpp\
			\
			data/MapGenerator/MapGenerator.cpp\
			data/MapGenerator/MapGeneratorAccessorElement.cpp\
			data/MapGenerator/MapGeneratorAccessorList.cpp\
			data/MapGenerator/MapGeneratorPublicChest.cpp\
			data/MapGenerator/MapGeneratorPublicCreateMap.cpp\
			\
			data/Monster/Monster.cpp\
			data/Monster/MonsterAccessor.cpp\
			data/Monster/MonsterPrivatePatern.cpp\
			data/Monster/MonsterPrivateSprite.cpp\
			data/Monster/MonsterPublicGain.cpp\
			data/Monster/MonsterPublicLife.cpp\
			data/Monster/MonsterPublicMoove.cpp\
			\
			data/Rubis/Rubis.cpp\
			data/Rubis/RubisAccessor.cpp\
			data/Rubis/RubisPrivateText.cpp\
			data/Rubis/RubisPublicUpdate.cpp\
			\
			data/Sword/Sword.cpp\
			data/Sword/SwordAccessor.cpp\
			data/Sword/SwordPrivateAnimation.cpp\
			data/Sword/SwordPrivateSprite.cpp\
			data/Sword/SwordPublicAnimation.cpp\
			data/Sword/SwordPublicOrientation.cpp\
			data/Sword/SwordPublicPower.cpp\
			\
			data/Wall/Wall.cpp\
			data/Wall/WallAccessor.cpp\
			data/Wall/WallPrivateSprite.cpp\
			data/Wall/WallPublicPosition.cpp\
			\

NAME	=	ZeldaLike.o

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))