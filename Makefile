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

DATA 	=	data/GamesWindow/GamesWindow.cpp\
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
			\
			data/Sword/Sword.cpp\
			\
			data/Wall/Wall.cpp\
			\

NAME	=	ZeldaLike

val:
	@(valgrind g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))

cpp:
	@(g++ -o $(NAME) $(OBJ) $(DATA) $(MODULE)) > /dev/null
	@(./$(NAME))