#include "Monster.hpp"

void Monster::setDamage(int power)
{
    m_life -= power;
    if(m_life <= 0)
    {
        m_alive = false;
        dropGain();
    }
}
void Monster::dropGain()
{
    m_Gain.choseGain(m_Sprite.getPosition());
    m_Sprite = m_Gain.getSpriteGain();
}