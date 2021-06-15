/**
 * @file JoueurPublicMove.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Joueur.hpp"

void Joueur::setPositionDown(void)
{
    float   x = m_Shero.getPosition().x,
            y = m_Shero.getPosition().y - 704;
    m_Shero.setPosition(sf::Vector2f(x, y));
}
void Joueur::setPositionUp(void)
{
    float   x = m_Shero.getPosition().x,
            y = m_Shero.getPosition().y + 704;
    m_Shero.setPosition(sf::Vector2f(x, y));
}
void Joueur::setPositionRight(void)
{
    float   x = m_Shero.getPosition().x - 1024,
            y = m_Shero.getPosition().y;
    m_Shero.setPosition(sf::Vector2f(x, y));
}
void Joueur::setPositionLeft(void)
{
    float   x = m_Shero.getPosition().x + 1024,
            y = m_Shero.getPosition().y;
    m_Shero.setPosition(sf::Vector2f(x, y));
}

void Joueur::recoilDown(void)
{
    m_Shero.move(sf::Vector2f(0.f, 64.f));
}
void Joueur::recoilLeft(void)
{
    m_Shero.move(sf::Vector2f(-64.f, 0.f));
}
void Joueur::recoilRight(void)
{
    m_Shero.move(sf::Vector2f(64.f, 0.f));
}
void Joueur::recoilUp(void)
{
    m_Shero.move(sf::Vector2f(0.f, -64.f));
}