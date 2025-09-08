/**
 * @file GamesWindow.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 1.1
 * @date 2021-05-31
 * @updated 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 * 
 */

#include "../../include/GamesWindow.hpp"

// Constructor / Destructor

// Constructor
GamesWindow::GamesWindow(void) {
    try {
        // Window size : (16* 64) * ((10 * 64) + 64) = 1024 * 704
        m_Window = std::make_unique<sf::RenderWindow>(
            sf::VideoMode(m_windowwidth, m_windowheight), 
            "Zelda Like v1.1",
            sf::Style::Titlebar | sf::Style::Close
        );
        
        if (!m_Window) {
            throw std::runtime_error("Failed to create SFML window");
        }
        
        // Configuration de la fenêtre
        m_Window->setVerticalSyncEnabled(true);
        
        Logger::debug("GamesWindow created successfully at %p", this);
        Logger::info("Window dimensions: %dx%d", m_windowwidth, m_windowheight);
        
    } catch (const std::exception& e) {
        Logger::error("Failed to create GamesWindow: %s", e.what());
        throw;
    }
}

// Destructor
GamesWindow::~GamesWindow(void) {
    if (m_Window) {
        m_Window->close();
        Logger::debug("GamesWindow destroyed at %p", this);
    }
}