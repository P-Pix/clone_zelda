/**
 * @file ChestPrivateSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Chest.hpp"

void Chest::loadSprite(const char *name)
{
    m_Texture.loadFromFile(name);
    m_Sprite.setTexture(m_Texture);
}