/**
 * @file MonsterPrivateSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Monster.hpp"

void Monster::initSprite(void)
{
    loadTexture(m_monster);
    loadSprite();
    loadPosition();
}
void Monster::loadSprite(void)
{
    m_Sprite.setTexture(m_Texture);
}
void Monster::loadTexture(const char *name)
{
    if(!m_Texture.loadFromFile(name))
    {
        std::cout << "error image " << name << std::endl;
    }
}
void Monster::loadPosition(void)
{
    m_Sprite.setPosition(sf::Vector2f(300.f, 300.f));
}