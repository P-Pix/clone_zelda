/**
 * @file MakeSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/MakeSprite.hpp"

MakeSprite::MakeSprite(void) {

}

MakeSprite::MakeSprite(const char *NameTexture) {
    loadSprite(NameTexture);
}

MakeSprite::~MakeSprite(void) {

}

void MakeSprite::loadSprite(const char *NameTexture) {
    if (!m_Texture.loadFromFile(NameTexture)) {
        std::cout << "error image " << NameTexture << std::endl;
    }
    m_Sprite.setTexture(m_Texture);

    sf::Image Image;
    Image.loadFromFile(NameTexture);
    m_sizex = Image.getSize().x;
    m_sizey = Image.getSize().y;
}