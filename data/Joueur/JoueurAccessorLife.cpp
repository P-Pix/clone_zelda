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
bool Joueur::isInvulnerable()
{
    return m_invulnerable;
}
std::vector<sf::Sprite> Joueur::getListSpriteHeart()
{
    return m_Heart.getListSprite();
}
sf::Sprite Joueur::getSpriteHeart(int number)
{
    return m_Heart.getSprite(number);
}