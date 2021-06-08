/**
 * @file ChestPublicGenerate.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Chest.hpp"

void Chest::generateChest(void)
{
    loadSprite(m_namechestclose);
    m_spawnchest = false;
    short spawn = std::rand() % 5;
    if(spawn == 1)
    {
        m_spawnchest = true;
        m_open = false;
    }
}
void Chest::openChest(void)
{
    if(!m_open)
    {
        loadSprite(m_namechestopen);
        m_Gain.choseGain(sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y + 64));
        m_Gain.getSpriteGain();
        m_open = !m_open;
    }
}
void Chest::isGet(void)
{
    m_Gain.isGet();
}