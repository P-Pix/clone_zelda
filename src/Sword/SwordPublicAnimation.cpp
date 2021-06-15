/**
 * @file SwordPublicAnimation.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Sword.hpp"

void Sword::animateAttack(void)
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