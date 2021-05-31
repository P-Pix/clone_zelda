# Zelda like
Goal : Create a Zelda like game

You need to install SFML for C++

## Compatibilty
OS|Compatibility
-|-
Ubuntu 20.04|Yes
## SFML

### WebSite
[SFML Home](https://www.sfml-dev.org/index.php)

[SFML Docs](https://www.sfml-dev.org/documentation/2.5.1-fr/)
### Install
```
sudo apt-get install libsfml-dev
```

## Using
### Compilation
```
g++ -o ZeldaLike.o main.cpp data/Chest/Chest.cpp data/Chest/ChestAccessor.cpp data/Chest/ChestPrivateSprite.cpp data/Chest/ChestPublicGenerate.cpp data/GainKill/GainKill.cpp data/GainKill/GainKillAccessor.cpp data/GainKill/GainKillPrivateSprite.cpp data/GainKill/GainKillPublicChose.cpp data/GamesWindow/GamesWindow.cpp data/GamesWindow/GamesWindowAccessor.cpp data/GamesWindow/GamesWindowPrivateCollide.cpp data/GamesWindow/GamesWindowPrivateControl.cpp data/GamesWindow/GamesWindowPrivateDraw.cpp data/GamesWindow/GamesWindowPrivateMap.cpp data/GamesWindow/GamesWindowPrivateMonster.cpp data/GamesWindow/GamesWindowPrivateSword.cpp data/GamesWindow/GamesWindowPublicWindow.cpp data/Ground/Ground.cpp data/Ground/GroundPrivateSprite.cpp data/Ground/GroundAccessor.cpp data/Ground/GroundPublicPosition.cpp data/Heart/Heart.cpp data/Heart/HeartPrivateSprite.cpp data/Heart/HeartAccessorSprite.cpp data/Heart/HeartPublicLifeBar.cpp data/Joueur/Joueur.cpp data/Joueur/JoueurAccessorLife.cpp data/Joueur/JoueurAccessorOrientation.cpp data/Joueur/JoueurAccessorPosition.cpp data/Joueur/JoueurAccessorRubis.cpp data/Joueur/JoueurPrivateMove.cpp data/Joueur/JoueurPrivateSprite.cpp data/Joueur/JoueurPublicAnimation.cpp data/Joueur/JoueurPublicLife.cpp data/Joueur/JoueurPublicMove.cpp data/Joueur/JoueurPublicRubis.cpp data/Joueur/JoueurPublicSwitchOrientation.cpp data/MapGenerator/MapGenerator.cpp data/MapGenerator/MapGeneratorAccessorElement.cpp data/MapGenerator/MapGeneratorAccessorList.cpp data/MapGenerator/MapGeneratorPublicChest.cpp data/MapGenerator/MapGeneratorPublicCreateMap.cpp data/Monster/Monster.cpp data/Monster/MonsterAccessor.cpp data/Monster/MonsterPrivatePatern.cpp data/Monster/MonsterPrivateSprite.cpp data/Monster/MonsterPublicGain.cpp data/Monster/MonsterPublicLife.cpp data/Monster/MonsterPublicMoove.cpp data/Rubis/Rubis.cpp data/Rubis/RubisAccessor.cpp data/Rubis/RubisPrivateText.cpp data/Rubis/RubisPublicUpdate.cpp data/Sword/Sword.cpp data/Sword/SwordAccessor.cpp data/Sword/SwordPrivateAnimation.cpp data/Sword/SwordPrivateSprite.cpp data/Sword/SwordPublicAnimation.cpp data/Sword/SwordPublicOrientation.cpp data/Sword/SwordPublicPower.cpp data/Wall/Wall.cpp data/Wall/WallAccessor.cpp data/Wall/WallPrivateSprite.cpp data/Wall/WallPublicPosition.cpp -lsfml-window -lsfml-system -lsfml-graphics
```
### Execution
```
./ZeldaLike.o
```
With Makefile
```
make cpp
```