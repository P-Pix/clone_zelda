/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void Joueur::setMaxLifeUp()
{
    m_maxlife += 4;
    m_life = m_maxlife;
}
void Joueur::setHeart()
{
    m_life += 4;
    if(m_life > m_maxlife)
    {
        m_life = m_maxlife;
    }
}
void Joueur::setDamage(int power)
{
    // creer les fram d'invulnérabilité
    m_life -= power;
    if(m_life <= 0)
    {
        m_life = 0;
        m_alive = false;
    }
}