/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GainKill.hpp"

void GainKill::choseGain(sf::Vector2f positionmonster)
{
    int valeur = rand() % 6;
    if(valeur == 0)
    {
        loadSprite(m_heartname);
        m_valorgainlife = 4;
        m_valorgainrubis = 0;
    }
    else if(valeur == 1)
    {
        loadSprite(m_greenrubisname);
        m_valorgainlife = 0;
        m_valorgainrubis = 1;
    }
    else if(valeur == 2)
    {
        loadSprite(m_bluerubisname);
        m_valorgainlife = 0;
        m_valorgainrubis = 5;
    }
    else if(valeur == 3)
    {
        loadSprite(m_redrubisname);
        m_valorgainlife = 0;
        m_valorgainrubis = 20;
    }
    else 
    {
        m_valorgainlife = 0;
        m_valorgainrubis = 0;
    }
    m_valorgainlife = 4;
    std::cout << valeur << std::endl;
    setPostionSprite(positionmonster);
}