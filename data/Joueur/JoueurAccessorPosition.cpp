/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

sf::Vector2f Joueur::getPosition()
{
    return m_Shero.getPosition();
}
sf::Vector2f Joueur::getPositionSword()
{
    sf::Vector2f positionsword(0.f, 0.f);
    if(m_orientationdown)
    {
        positionsword.x = m_Shero.getPosition().x;
        positionsword.y = m_Shero.getPosition().y + 64;
        return positionsword;
    }
    else if(m_orientationleft)
    {
        positionsword.x = m_Shero.getPosition().x;
        positionsword.y = m_Shero.getPosition().y;
        return positionsword;
    }
    else if(m_orientationright)
    {
        positionsword.x = m_Shero.getPosition().x + 64;
        positionsword.y = m_Shero.getPosition().y + 64;
        return positionsword;
    }
    else if(m_orientationup)
    {
        positionsword.x = m_Shero.getPosition().x + 64;
        positionsword.y = m_Shero.getPosition().y;
        return positionsword;
    }
    return m_Shero.getPosition();
}
int Joueur::getSpeed()
{
    return m_vitesse;
}