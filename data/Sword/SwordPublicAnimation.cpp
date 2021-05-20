#include "Sword.hpp"

void Sword::animateAttack()
{
    m_animationfram ++;
    if(m_animationfram == 15)
    {
        endAnimation();
    }
}
void Sword::startAnimation(sf::Vector2f positionsword,int playerorientation)
{
    m_animationfram = 0;
    m_aniamtionexe = true;
    m_rotate = playerorientation;
    m_Sprite.setRotation(m_rotate);
    m_VectorAniamtor.x = positionsword.x;
    m_VectorAniamtor.y = positionsword.y;
    setBasicPosition();
}