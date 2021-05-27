/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

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