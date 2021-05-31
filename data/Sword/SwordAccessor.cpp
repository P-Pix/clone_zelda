/**
 * @file SwordAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Sword.hpp"

sf::Sprite Sword::getSprite()
{
    return m_Sprite;
}
sf::Vector2f Sword::getPosition()
{
    return m_Sprite.getPosition();
}
int Sword::getPower()
{
    return m_power;
}
bool Sword::getExecution()
{
    return m_aniamtionexe;
}
bool Sword::getAttackUp()
{
    return m_animationup;
}
bool Sword::getAttackLeft()
{
    return m_animationleft;
}
bool Sword::getAttackRight()
{
    return m_animationright;
}
bool Sword::getAttackDown()
{
    return m_animationdown;
}