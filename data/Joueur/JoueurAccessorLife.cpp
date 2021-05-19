/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

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