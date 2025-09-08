/**
 * @file JoueurPrivateSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/JoueurLegacy.hpp"

sf::Sprite Joueur::loadSprite(const char *name, sf::Vector2f vector) {
    sf::Sprite sprite;
    loadTexture(name);
    sprite.setTexture(m_Thero);
    sprite.setPosition(vector);
    sprite.setScale(2, 2);
    return sprite;
}

void Joueur::loadTexture(const char *name) {
    if (!m_Thero.loadFromFile(name)) {
        std::cout << "error image " << name << std::endl;
    }
}