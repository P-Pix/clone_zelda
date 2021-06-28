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
Linux
```
sudo apt-get install libsfml-dev
```
[Window / Mac](https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php)
## Using
### Compilation
```
g++ -o ZeldaLike.o main.cpp src/Chest/Accessor.cpp src/Chest/Constructor.cpp src/Chest/Generate.cpp src/Chest/Sprite.cpp src/Gain/Accessor.cpp src/Gain/Chose.cpp src/Gain/Constructor.cpp src/Gain/Sprite.cpp src/Game/Accessor.cpp src/Game/Collide.cpp src/Game/Constructor.cpp src/Game/Control.cpp src/Game/Draw.cpp src/Game/Map.cpp src/Game/Monster.cpp src/Game/Sword.cpp src/GamesWindow/Accessor.cpp src/GamesWindow/Constructor.cpp src/GamesWindow/Control.cpp src/GamesWindow/Draw.cpp src/GamesWindow/Window.cpp src/Ground/Accessor.cpp src/Ground/Constructor.cpp src/Ground/Position.cpp src/Ground/Sprite.cpp src/Heart/Accessor.cpp src/Heart/Constructor.cpp src/Heart/LifeBar.cpp src/Heart/Sprite.cpp src/Joueur/AccessorLife.cpp src/Joueur/AccessorOrientation.cpp src/Joueur/AccessorPosition.cpp src/Joueur/AccessorRubis.cpp src/Joueur/Animation.cpp src/Joueur/Constructor.cpp src/Joueur/Life.cpp src/Joueur/Move.cpp src/Joueur/Orientation.cpp src/Joueur/Rubis.cpp src/Joueur/Sprite.cpp src/MakeSprite/Constructor.cpp src/MapGenerator/Accessor.cpp src/MapGenerator/Chest.cpp src/MapGenerator/Constructor.cpp src/MapGenerator/CreateMap.cpp src/Monster/Constructor.cpp src/Monster/Accessor.cpp src/Monster/Gain.cpp src/Monster/Life.cpp src/Monster/Moove.cpp src/Monster/Patern.cpp src/Monster/Sprite.cpp src/Rubis/Constructor.cpp src/Rubis/Accessor.cpp src/Rubis/Text.cpp src/Rubis/Update.cpp src/Sword/Accessor.cpp src/Sword/Animation.cpp src/Sword/Constructor.cpp src/Sword/Orientation.cpp src/Sword/Power.cpp src/Sword/Sprite.cpp src/Wall/Accessor.cpp src/Wall/Constructor.cpp src/Wall/Position.cpp src/Wall/Sprite.cpp -lsfml-window -lsfml-system -lsfml-graphics
```
### Execution
```
./ZeldaLike.o
```
### Compilation and Execution
With Makefile
```
make cpp
```