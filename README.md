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
g++ -o ZeldaLike.o main.cpp src/Chest/*.cpp src/Gain/*.cpp src/Game/*.cpp src/GamesWindow/*.cpp src/Ground/*.cpp src/Heart/*.cpp src/Joueur/*.cpp src/MakeSprite/*.cpp src/MapGenerator/*.cpp src/Monster/*.cpp src/Rubis/*.cpp src/Sword/*.cpp src/Wall/*.cpp -lsfml-window -lsfml-system -lsfml-graphics
```
With Makefile
```
make cpp
```
### Execution
```
./ZeldaLike.o
```
With Makefile
```
make run
```
