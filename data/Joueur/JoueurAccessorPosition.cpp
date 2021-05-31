/**
 * @file JoueurAccessorPosition.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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