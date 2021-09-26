/**
 * @file GamesWindow.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/GamesWindow.hpp"

// Constructor / Destructor

// Constructor
GamesWindow::GamesWindow(void) {
    // Window size : (16* 64) * ((10 * 64) + 64) = 1024 * 704
    this->m_Window = nullptr;
    this->m_Window = new sf::RenderWindow(sf::VideoMode(m_windowwidth, m_windowheight), "Zelda Like");
    //std::cout << "window create " << this << std::endl;
}

// Destructor
GamesWindow::~GamesWindow(void) {
    //std::cout << "window delete " << this << std::endl;
}