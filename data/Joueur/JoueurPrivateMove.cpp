/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

void Joueur::moveLeft()
{
    m_Shero.move(sf::Vector2f(m_vitesse * -1.f, 0.f));
}
void Joueur::moveRight()
{
    m_Shero.move(sf::Vector2f(m_vitesse * 1.f, 0.f));
}
void Joueur::moveUp()
{
    m_Shero.move(sf::Vector2f(0.f, m_vitesse * -1.f));
}
void Joueur::moveDown()
{
    m_Shero.move(sf::Vector2f(0.f, m_vitesse * 1.f));
}