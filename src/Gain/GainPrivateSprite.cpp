/**
 * @file GainPrivateSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Gain.hpp"

void Gain::loadSprite(const char *name)
{
    loadTexture(name);
    m_Sprite.setTexture(m_Texture);
}
void Gain::loadTexture(const char *name)
{
    if(!m_Texture.loadFromFile(name))
    {
        std::cout << "error image " << name << std::endl;
    }
}
void Gain::setPostionSprite(sf::Vector2f position)
{
    m_Sprite.setPosition(position);
}