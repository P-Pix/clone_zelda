/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GainKill.hpp"

void GainKill::choseGain(sf::Vector2f positionmonster)
{
    m_gain = true;
    std::srand(std::time(nullptr));
    int valeur = std::rand() % 20;
    if(valeur <= 5)
    {
        loadSprite(m_heartname);
        m_valorgainlife = 4;
        m_valorgainrubis = 0;
    }
    else if(valeur <= 12)
    {
        loadSprite(m_greenrubisname);
        m_valorgainlife = 0;
        m_valorgainrubis = 1;
    }
    else if(valeur <= 14)
    {
        loadSprite(m_bluerubisname);
        m_valorgainlife = 0;
        m_valorgainrubis = 5;
    }
    else if(valeur == 15)
    {
        loadSprite(m_redrubisname);
        m_valorgainlife = 0;
        m_valorgainrubis = 20;
    }
    else 
    {
        isGet();
    }
    setPostionSprite(positionmonster);
}
void GainKill::isGet()
{
    m_gain = false;
    loadSprite(m_emptyname);
}