/**
 * @file JoueurPublicLife.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Joueur.hpp"

void Joueur::setMaxLifeUp()
{
    m_Heart.setMaxLifeUp();
}
void Joueur::setHeart(int life)
{
    m_Heart.setHeart(life);
}
void Joueur::setDamage(int power)
{
    m_Heart.setDamage(power);
}
void Joueur::frameInvulnerable()
{
    m_Heart.frameInvulnerable();
}