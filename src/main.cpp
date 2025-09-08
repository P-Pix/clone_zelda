/**
 * @file main.cpp
 * @author Guillaume LEMONNIER
 * @date 2021-05-31
 * @updated 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 * 
 */

#include <iostream>
#include <memory>
#include <exception>
#include "../include/GamesWindow.hpp"
#include "../include/Logger.hpp"
#include "../include/Config.hpp"

/// Point d'entrée du programme
int main(void);

int main(void) {
    try {
        // Initialisation du système de logging
        #ifdef DEBUG
            Logger::setMinLevel(LogLevel::LOG_DEBUG);
            Logger::enableFileLogging("zelda_debug.log");
            Logger::debug("Application started in DEBUG mode");
        #else
            Logger::setMinLevel(LogLevel::INFO);
            Logger::info("Application started in RELEASE mode");
        #endif
        
        Logger::info("Initializing ZeldaLike Game Engine v1.1");
        Logger::info("Window size: %dx%d", Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
        
        // Création de la fenêtre de jeu
        auto window = std::make_unique<GamesWindow>();
        
        if (!window) {
            Logger::error("Failed to create game window");
            return EXIT_FAILURE;
        }
        
        window->limitFramerate(Config::FRAMERATE_LIMIT);
        Logger::info("Game window created successfully");
        Logger::info("Framerate limited to %d FPS", Config::FRAMERATE_LIMIT);
        
        // Boucle principale du jeu
        Logger::info("Starting main game loop");
        while (window->isRunning()) {
            window->controlWindow();
            window->verificationWindow();
            window->updateWindow();
        }
        
        Logger::info("Game loop ended normally");
        Logger::info("ZeldaLike application terminated successfully");
        
    } catch (const std::exception& e) {
        Logger::error("Fatal error: %s", e.what());
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        Logger::error("Unknown fatal error occurred");
        std::cerr << "Unknown fatal error occurred" << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}