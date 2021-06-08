/**
 * @file GainAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Gain.hpp"

sf::Sprite Gain::getSpriteGain(void)
{
    return m_Sprite;
}
int Gain::getValorGainLife(void)
{
    return m_valorgainlife;
}
int Gain::getValorGainRubis(void)
{
    return m_valorgainrubis;
}
bool Gain::thereGain(void)
{
    return m_gain;
}