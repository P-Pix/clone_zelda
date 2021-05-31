/**
 * @file Rubis.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Rubis.hpp"

Rubis::Rubis()
{
    m_Texture.loadFromFile(m_nameimage);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(sf::Vector2f(640.f, 16.f));
    m_Font.loadFromFile(m_namefont);

    generateText();
}
Rubis::~Rubis()
{
    
}