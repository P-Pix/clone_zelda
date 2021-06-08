/**
 * @file GroundPrivateSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Ground.hpp"

void Ground::initSprite(void)
{
    loadTexture();
    loadSprite();
}
void Ground::loadSprite(void)
{
    m_Sprite.setTexture(m_Texture);
}
void Ground::loadTexture(void)
{
    if(!m_Texture.loadFromFile(m_name))
    {
        std::cout << "error image " << m_name << std::endl;
    }
}