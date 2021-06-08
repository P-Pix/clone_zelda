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

sf::Sprite Monster::getSprite(void)
{
    return m_Sprite;
}
sf::Vector2f Monster::getNextPosition(void)
{
    return m_Patern[m_moveaction];
}
sf::Vector2f Monster::getPosition(void)
{
    return m_Sprite.getPosition();
}
int Monster::getPower(void)
{
    return m_power;
}
bool Monster::isAlive(void)
{
    return m_Heart.isAlive();
}
int Monster::getGainLifeValor(void)
{
    return m_Gain.getValorGainLife();
}
int Monster::getGainRubisValor(void)
{
    return m_Gain.getValorGainRubis();
}
bool Monster::thereGain(void)
{
    return m_Gain.thereGain();
}
bool Monster::isInvulnerable(void)
{
    return m_Heart.isInvulnerable();
}
Monster* Monster::getAdress(void)
{
    return this;
}
Monster Monster::getMonster(void)
{
    return *this;
}