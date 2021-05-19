/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Heart.hpp"

sf::Sprite Heart::setSpritePosition(sf::Sprite sprite, sf::Vector2f position)
{
    sprite.setPosition(position);
    return sprite;
}

void Heart::initConstructor()
{
    m_T0Heart.loadFromFile(m_name0);
    m_S0Heart.setTexture(m_T0Heart);

    m_T1Heart.loadFromFile(m_name1);
    m_S1Heart.setTexture(m_T1Heart);
    
    m_T2Heart.loadFromFile(m_name2);
    m_S2Heart.setTexture(m_T2Heart);

    m_T3Heart.loadFromFile(m_name3);
    m_S3Heart.setTexture(m_T3Heart);

    m_T4Heart.loadFromFile(m_name4);
    m_S4Heart.setTexture(m_T4Heart);
}