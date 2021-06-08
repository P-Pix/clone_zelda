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

int Joueur::getLife(void)
{
    return m_Heart.getLife();
}
int Joueur::getMaxLife(void)
{
    return m_Heart.getMaxLife();
}
bool Joueur::isAlive(void)
{
    return m_Heart.isAlive();
}
bool Joueur::isInvulnerable(void)
{
    return m_Heart.isInvulnerable();
}
std::vector<sf::Sprite> Joueur::getListSpriteHeart(void)
{
    return m_Heart.getListSprite();
}
sf::Sprite Joueur::getSpriteHeart(int number)
{
    return m_Heart.getSprite(number);
}