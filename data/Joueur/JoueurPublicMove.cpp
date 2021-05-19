/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

void Joueur::setPositionDown()
{
    float   x = m_Shero.getPosition().x,
            y = m_Shero.getPosition().y - 640;
    m_Shero.setPosition(sf::Vector2f(x, y));
}
void Joueur::setPositionUp()
{
    float   x = m_Shero.getPosition().x,
            y = m_Shero.getPosition().y + 640;
    m_Shero.setPosition(sf::Vector2f(x, y));
}
void Joueur::setPositionRight()
{
    float   x = m_Shero.getPosition().x - 1088,
            y = m_Shero.getPosition().y;
    m_Shero.setPosition(sf::Vector2f(x, y));
}
void Joueur::setPositionLeft()
{
    float   x = m_Shero.getPosition().x + 1088,
            y = m_Shero.getPosition().y;
    m_Shero.setPosition(sf::Vector2f(x, y));
}

void Joueur::recoilDown()
{
    m_Shero.move(sf::Vector2f(0.f, 64.f));
}
void Joueur::recoilLeft()
{
    m_Shero.move(sf::Vector2f(-64.f, 0.f));
}
void Joueur::recoilRight()
{
    m_Shero.move(sf::Vector2f(64.f, 0.f));
}
void Joueur::recoilUp()
{
    m_Shero.move(sf::Vector2f(0.f, -64.f));
}