/**
 * @file Config.hpp
 * @author Guillaume LEMONNIER
 * @brief Configuration globale du jeu
 * @version 1.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 */

#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

namespace Config {
    // Dimensions de la fenêtre
    constexpr int WINDOW_WIDTH = 1024;
    constexpr int WINDOW_HEIGHT = 768;
    constexpr int FRAMERATE_LIMIT = 60;
    
    // Taille des sprites
    constexpr int SPRITE_SIZE = 64;
    
    // Limites de la carte
    constexpr int LIMIT_UP_GAME = 64;
    constexpr int LIMIT_DOWN_GAME = 768;
    constexpr int LIMIT_RIGHT_GAME = 1024;
    constexpr int LIMIT_LEFT_GAME = 0;
    
    // Types de collision
    constexpr int NO_COLLIDE = 0;
    constexpr int LEFT_COLLIDE = 1;
    constexpr int RIGHT_COLLIDE = 2;
    constexpr int UP_COLLIDE = 3;
    constexpr int DOWN_COLLIDE = 4;
    
    // Paramètres de gameplay
    constexpr int DEFAULT_PLAYER_SPEED = 5;
    constexpr int DEFAULT_MONSTER_POWER = 4;
    constexpr float RECOIL_DISTANCE = 64.0f;
    
    // Chemins des ressources
    namespace Paths {
        constexpr const char* FONTS_DIR = "font/";
        constexpr const char* IMAGES_DIR = "image/";
        constexpr const char* MAPS_DIR = "maping/";
        
        // Fonts
        constexpr const char* MAIN_FONT = "font/SuperLegendBoy.ttf";
        constexpr const char* ALT_FONT = "font/lemon_milk.ttf";
        
        // Images communes
        constexpr const char* GROUND_TEXTURE = "image/ground.png";
        constexpr const char* WATER_TEXTURE = "image/water.png";
        constexpr const char* WALL_TEXTURE = "image/bloc.png";
    }
    
    // Couleurs du jeu
    namespace Colors {
        inline const sf::Color BACKGROUND = sf::Color::Black;
        inline const sf::Color UI_TEXT = sf::Color::White;
        inline const sf::Color UI_HIGHLIGHT = sf::Color::Yellow;
        inline const sf::Color HEALTH_FULL = sf::Color::Red;
        inline const sf::Color HEALTH_EMPTY = sf::Color(64, 64, 64);
    }
    
    // Messages de debug
    namespace Debug {
        constexpr bool ENABLE_CONSOLE_OUTPUT = true;
        constexpr bool SHOW_FPS = false;
        constexpr bool SHOW_COLLISION_BOXES = false;
    }
}

#endif // _CONFIG_HPP_
