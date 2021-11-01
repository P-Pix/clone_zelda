/**
 * @file GamesWindowPrivateControl.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/GamesWindow.hpp"

void GamesWindow::pollEvent(void) {
    if (this->m_Window->pollEvent(this->m_Event)) {
        if (this->m_Event.type == sf::Event::Closed) {
            this->m_Window->close();
        } else if (this->m_Event.type == sf::Event::KeyPressed) {
            if (this->m_Event.key.code == sf::Keyboard::Escape) {
                this->m_Window->close();
            } else if (this->m_Event.key.code == sf::Keyboard::Down) {
                m_Game.keyDown();
            } else if (this->m_Event.key.code == sf::Keyboard::Up) {
                m_Game.keyUp();
            } else if (this->m_Event.key.code == sf::Keyboard::Left) {
                m_Game.keyLeft();
            } else if (this->m_Event.key.code == sf::Keyboard::Right) {
                m_Game.keyRight();
            } else if (this->m_Event.key.code == sf::Keyboard::Space) {
                m_Game.keySpace();
            }
        }
    }
}