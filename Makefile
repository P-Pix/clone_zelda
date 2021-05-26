###
### Guillaume LEMONNIER
### Developpement autonome
### Tout droits reservé
###

SRC		=	main.cpp\

OBJ		=	$(SRC:.cpp = .o)

MODULE	=	-lsfml-window\
			-lsfml-system\
			-lsfml-graphics\

DATA 	=	data/GainKill/GainKill.cpp\
			data/GainKill/GainKillAccessor.cpp\
			data/GainKill/GainKillPrivateSprite.cpp\
			data/GainKill/GainKillPublicChose.cpp\
			\
			data/GamesWindow/GamesWindow.cpp\
			data/GamesWindow/GamesWindowAccessor.cpp\
			data/GamesWindow/GamesWindowPrivateCollide.cpp\
			data/GamesWindow/GamesWindowPrivateControl.cpp\
			data/GamesWindow/GamesWindowPrivateDraw.cpp\
			data/GamesWindow/GamesWindowPrivateHeart.cpp\
			data/GamesWindow/GamesWindowPrivateMap.cpp\
			data/GamesWindow/GamesWindowPrivateMonster.cpp\
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
			data/Joueur/JoueurPrivateMove.cpp\
			data/Joueur/JoueurPrivateSprite.cpp\
			data/Joueur/JoueurPublicAnimation.cpp\
			data/Joueur/JoueurPublicLife.cpp\
			data/Joueur/JoueurPublicMove.cpp\
			data/Joueur/JoueurPublicSwitchOrientation.cpp\
			\
			data/MapGenerator/MapGenerator.cpp\
			data/MapGenerator/MapGeneratorAccessorElement.cpp\
			data/MapGenerator/MapGeneratorAccessorList.cpp\
			data/MapGenerator/MapGeneratorPublicCreateMap.cpp\
			\
			data/Monster/Monster.cpp\
			data/Monster/MonsterAccessor.cpp\
			data/Monster/MonsterPrivatePatern.cpp\
			data/Monster/MonsterPrivateSprite.cpp\
			data/Monster/MonsterPublicLife.cpp\
			data/Monster/MonsterPublicMoove.cpp\
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

NAME	=	ZeldaLike

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))