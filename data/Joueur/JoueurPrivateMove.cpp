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

void Joueur::makeListeAnimation()
{
    m_AnimationDown.push_back(m_ncf0);
    m_AnimationDown.push_back(m_ncf1);
    m_AnimationDown.push_back(m_ncf2);
    m_AnimationDown.push_back(m_ncf3);
    m_AnimationDown.push_back(m_ncf4);
    m_AnimationDown.push_back(m_ncf5);
    m_AnimationDown.push_back(m_ncf6);
    m_AnimationDown.push_back(m_ncf7);
}