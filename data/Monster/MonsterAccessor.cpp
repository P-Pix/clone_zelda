/**
 * @file MonsterAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Monster.hpp"

sf::Sprite Monster::getSprite()
{
    return m_Sprite;
}
sf::Vector2f Monster::getNextPosition()
{
    return m_Patern[m_moveaction];
}
sf::Vector2f Monster::getPosition()
{
    return m_Sprite.getPosition();
}
int Monster::getPower()
{
    return m_power;
}
bool Monster::isAlive()
{
    return m_Heart.isAlive();
}
int Monster::getGainLifeValor()
{
    return m_Gain.getValorGainLife();
}
int Monster::getGainRubisValor()
{
    return m_Gain.getValorGainRubis();
}
bool Monster::thereGain()
{
    return m_Gain.thereGain();
}
bool Monster::isInvulnerable()
{
    return m_Heart.isInvulnerable();
}