/**
 * @file MonsterPublicMoove.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Monster.hpp"

void Monster::moove()
{
    m_Sprite.move(m_Patern[m_moveaction]);
}
void Monster::recoilDown()
{
    m_Sprite.move(sf::Vector2f(0.f, 64.f));
}
void Monster::recoilLeft()
{
    m_Sprite.move(sf::Vector2f(-64.f, 0.f));
}
void Monster::recoilUp()
{
    m_Sprite.move(sf::Vector2f(0.f, -64.f));
}
void Monster::recoilRight()
{
    m_Sprite.move(sf::Vector2f(64.f, 0.f));
}
void Monster::nextPosition()
{
    m_moveaction ++;
    if(m_moveaction == m_Patern.size())
    {
        m_moveaction = 0;
    }
}