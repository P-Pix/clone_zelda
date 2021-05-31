/**
 * @file JoueurAccessorLife.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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