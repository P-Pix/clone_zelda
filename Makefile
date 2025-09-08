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

DATA1	=	src/main.cpp\
			src/Logger.cpp\
			src/Entity.cpp\
			src/Character.cpp\
			src/StaticEntity.cpp\
			src/Chest/*.cpp\
			src/Gain/*.cpp\
			src/Game/*.cpp\
			src/GamesWindow/*.cpp\
			src/Ground/*.cpp\
			src/Heart/*.cpp\
			src/Joueur/*.cpp\
			src/MakeSprite/*.cpp\
			src/MapGenerator/*.cpp\
			src/Monster/*.cpp\
			src/Rubis/*.cpp\
			src/Sword/*.cpp\
			src/Wall/*.cpp\

DATA2	=	SecondVersion/src/main.cpp\

NAME	=	ZeldaLike
EXECUTABLE = $(NAME).out

VERSION	=	-std=c++17\
			-Wall\
			-Wextra\
			-O2\

debug:
	@echo "🔨 Building in debug mode..."
	@g++ -g -DDEBUG -o $(NAME)-debug $(DATA1) $(MODULE) $(VERSION)
	@echo "✅ Debug build complete: $(NAME)-debug"

release:
	@echo "🔨 Building in release mode..."
	@g++ -o $(EXECUTABLE) $(DATA1) $(MODULE) $(VERSION)
	@echo "✅ Release build complete: $(EXECUTABLE)"

# Backward compatibility
val1: debug
	@echo "⚠️  Note: 'val1' is deprecated, use 'debug' instead"

cpp1: release
	@echo "⚠️  Note: 'cpp1' is deprecated, use 'release' instead"

cpp: release

cpp2:
	@(g++ -o $(NAME) $(DATA2) $(MODULE) $(VERSION)) > /dev/null

run: release
	@echo "🎮 Starting ZeldaLike..."
	@./$(EXECUTABLE)

run-debug: debug
	@echo "🐛 Starting ZeldaLike in debug mode..."
	@./$(NAME)-debug

clean:
	@echo "🧹 Cleaning build files..."
	@rm -f $(NAME)-debug $(EXECUTABLE) $(NAME).obj tests/test_utils
	@echo "✅ Clean complete"

valgrind: debug
	@echo "🔍 Running with Valgrind..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)-debug

install-deps:
	@echo "📦 Installing SFML dependencies..."
	@sudo apt-get update
	@sudo apt-get install libsfml-dev

# Tests
test: 
	@echo "🧪 Building and running tests..."
	@g++ -o tests/test_utils tests/test_utils.cpp src/Logger.cpp $(MODULE) $(VERSION) -Iinclude
	@./tests/test_utils
	@echo "✅ Tests completed"

test-clean:
	@rm -f tests/test_utils

.PHONY: debug release cpp1 cpp2 run run-debug clean valgrind install-deps test test-clean