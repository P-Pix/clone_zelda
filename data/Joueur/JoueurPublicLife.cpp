/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

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
}
void Joueur::frameInvulnerable()
{
    if(m_invulnerability == 120)
    {
        m_invulnerable = false;
    }
    m_invulnerability ++;
}