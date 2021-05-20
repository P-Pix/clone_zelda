#include "Monster.hpp"

void Monster::setDamage(int power)
{
    m_life -= power;
    if(m_life <= 0)
    {
        m_alive = false;
    }
}