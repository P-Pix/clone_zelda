/**
 * @file JoueurPublicAnimation.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Joueur.hpp"

void Joueur::animationMoveRight()
{
    moveAniamtion(m_moveright, m_AnimationRight);
    if(m_moveright == 32)
    {
        m_moveright = 0;
    }
    m_moveright ++;
    moveRight();
}
void Joueur::animationMoveLeft()
{
    moveAniamtion(m_moveleft, m_AnimationLeft);
    if(m_moveleft == 32)
    {
        m_moveleft = 0;
    }
    m_moveleft ++;
    moveLeft();
}
void Joueur::animationMoveUp()
{
    moveAniamtion(m_moveup, m_AnimationUp);
    if(m_moveup == 32)
    {
        m_moveup = 0;
    }
    m_moveup ++;
    moveUp();
}
void Joueur::animationMoveDown()
{
    moveAniamtion(m_movedown, m_AnimationDown);
    if(m_movedown == 32)
    {
        m_movedown = 0;
    }
    m_movedown ++;
    moveDown();
}