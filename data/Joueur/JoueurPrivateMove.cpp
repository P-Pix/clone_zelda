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
    // Liste aniamtion Down
    m_AnimationDown.push_back(m_ncf0);
    m_AnimationDown.push_back(m_ncf1);
    m_AnimationDown.push_back(m_ncf2);
    m_AnimationDown.push_back(m_ncf3);
    m_AnimationDown.push_back(m_ncf4);
    m_AnimationDown.push_back(m_ncf5);
    m_AnimationDown.push_back(m_ncf6);
    m_AnimationDown.push_back(m_ncf7);

    // Liste aniamtion Left
    m_AnimationLeft.push_back(m_ncf0);
    m_AnimationLeft.push_back(m_ncf1);
    m_AnimationLeft.push_back(m_ncf2);
    m_AnimationLeft.push_back(m_ncf3);
    m_AnimationLeft.push_back(m_ncf4);
    m_AnimationLeft.push_back(m_ncf5);
    m_AnimationLeft.push_back(m_ncf6);
    m_AnimationLeft.push_back(m_ncf7);

    // Liste aniamtion Right
    m_AnimationRight.push_back(m_ncf0);
    m_AnimationRight.push_back(m_ncf1);
    m_AnimationRight.push_back(m_ncf2);
    m_AnimationRight.push_back(m_ncf3);
    m_AnimationRight.push_back(m_ncf4);
    m_AnimationRight.push_back(m_ncf5);
    m_AnimationRight.push_back(m_ncf6);
    m_AnimationRight.push_back(m_ncf7);

    // Liste aniamtion Up
    m_AnimationUp.push_back(m_ncf0);
    m_AnimationUp.push_back(m_ncf1);
    m_AnimationUp.push_back(m_ncf2);
    m_AnimationUp.push_back(m_ncf3);
    m_AnimationUp.push_back(m_ncf4);
    m_AnimationUp.push_back(m_ncf5);
    m_AnimationUp.push_back(m_ncf6);
    m_AnimationUp.push_back(m_ncf7);
}