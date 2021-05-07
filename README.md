# Zelda like
Goal : Create a Zelda like game

You need to install SFML for C++

# SFML
```
sudo apt-get install libsfml-dev
```

# Compilation / Execution
With Makefile
```
make cpp
./main
```
Without Makefile
```
g++ -o main.cpp main data/Monster.cpp data/GamesWindow.cpp data/Joueur.cpp data/Wall.cpp data/Ground.cpp data/Heart.cpp data/MapGenerator.cpp data/Sword.cpp -lsfml-window -lsfml-system -lsfml-graphics
./main
```