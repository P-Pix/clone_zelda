/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int Joueur::getLife()
{
    return m_life;
}
int Joueur::getMaxLife()
{
    return m_maxlife;
}
bool Joueur::isAlive()
{
    return m_alive;
}