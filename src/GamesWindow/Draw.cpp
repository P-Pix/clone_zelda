/**
 * @file GamesWindowPrivateDraw.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/GamesWindow.hpp"

void GamesWindow::drawSprite(sf::Sprite sprite) {
    this->m_Window->draw(sprite);
}

void GamesWindow::drawText(sf::Text text) {
    this->m_Window->draw(text);
}

void GamesWindow::drawVectorSprite(std::vector <sf::Sprite> vector) {
    for (int number = 0; number < vector.size(); number++) {
        drawSprite(vector[number]);
    }
}

void GamesWindow::drawVectorText(std::vector <sf::Text> vector) {
    for (int number = 0; number < vector.size(); number++) {
        drawText(vector[number]);
    }
}