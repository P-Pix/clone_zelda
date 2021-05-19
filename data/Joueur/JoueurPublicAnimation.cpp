/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

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
void Joueur::moveAniamtion(int frame, std::vector<const char * > liste)
{
    if(frame % 32 == 0)
    {
        loadTexture(liste[0]);
    }
    else if(frame % 32 == 4)
    {
        loadTexture(liste[1]);
    }
    else if(frame % 32 == 8)
    {
        loadTexture(liste[2]);
    }
    else if(frame % 32 == 12)
    {
        loadTexture(liste[3]);
    }
    else if(frame % 32 == 16)
    {
        loadTexture(liste[4]);
    }
    else if(frame % 32 == 20)
    {
        loadTexture(liste[5]);
    }
    else if(frame % 32 == 24)
    {
        loadTexture(liste[6]);
    }
    else if(frame % 32 == 28)
    {
        loadTexture(liste[7]);
    }
}