/**
 * @file GainKillAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GainKill.hpp"

sf::Sprite GainKill::getSpriteGain()
{
    return m_Sprite;
}
int GainKill::getValorGainLife()
{
    return m_valorgainlife;
}
int GainKill::getValorGainRubis()
{
    return m_valorgainrubis;
}
bool GainKill::thereGain()
{
    return m_gain;
}