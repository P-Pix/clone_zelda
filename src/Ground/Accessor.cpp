/**
 * @file GroundAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Ground.hpp"

// Sprite
std::vector <sf::Sprite> Ground::getListSprite(void) {
    return m_ListeSprite;
}

sf::Sprite Ground::getSprite(void) {
    return m_Sprite;
}

// Adress
Ground *Ground::getAdress(void) {
    return this;
}