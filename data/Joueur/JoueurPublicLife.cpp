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
    m_maxlife += 4;
    m_life = m_maxlife;
}
void Joueur::setHeart(int life)
{
    m_life += life;
    if(m_life > m_maxlife)
    {
        m_life = m_maxlife;
    }
    m_Heart.updateHeart(m_life, m_maxlife);
}
void Joueur::setDamage(int power)
{
    if(!m_invulnerable)
    {
        m_life -= power;
        if(m_life <= 0)
        {
            m_life = 0;
            m_alive = false;
        }
        m_invulnerable = true;
        m_invulnerability = 0;
    }
    m_Heart.updateHeart(m_life, m_maxlife);
}
void Joueur::frameInvulnerable()
{
    if(m_invulnerability == 120)
    {
        m_invulnerable = false;
    }
    m_invulnerability ++;
}