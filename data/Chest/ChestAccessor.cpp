/**
 * @file ChestAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Chest.hpp"

sf::Sprite Chest::getSprite()
{
    return m_Sprite;
}
bool Chest::getChest()
{
    return m_spawnchest;
}
int Chest::getValorLife()
{
    return m_Gain.getValorGainLife();
}
int Chest::getValorRubis()
{
    return m_Gain.getValorGainRubis();
}
sf::Sprite Chest::getSpriteGain()
{
    return m_Gain.getSpriteGain();
}