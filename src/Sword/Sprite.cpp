/**
 * @file SwordPrivateSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Sword.hpp"

void Sword::loadTexture(void) {
    if (!m_Texture.loadFromFile(m_picture)) {
        std::cout << "error load " << m_picture << std::endl;
    }
}

void Sword::loadSprite(void) {
    m_Sprite.setTexture(m_Texture);
}