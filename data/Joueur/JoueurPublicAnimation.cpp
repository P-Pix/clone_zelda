/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

void Joueur::animationMoveRight()
{
    if(m_moveright % 4 == 0)
    {
        loadTexture(m_ncf1);
    }
    else if(m_moveright % 4 == 1)
    {
        loadTexture(m_ncf2);
    }
    else if(m_moveright % 4 == 2)
    {
        loadTexture(m_ncf3);
    }
    else
    {
        loadTexture(m_ncf4);
    }
    m_moveright ++;
    moveRight();
}
void Joueur::animationMoveLeft()
{
    if(m_moveleft % 4 == 0)
    {
        loadTexture(m_ncf1);
    }
    else if(m_moveleft % 4 == 1)
    {
        loadTexture(m_ncf2);
    }
    else if(m_moveleft % 4 == 2)
    {
        loadTexture(m_ncf3);
    }
    else
    {
        loadTexture(m_ncf4);
    }
    m_moveleft ++;
    moveLeft();
}
void Joueur::animationMoveUp()
{
    if(m_moveup % 4 == 0)
    {
        loadTexture(m_ncf1);
    }
    else if(m_moveup % 4 == 1)
    {
        loadTexture(m_ncf2);
    }
    else if(m_moveup % 4 == 2)
    {
        loadTexture(m_ncf3);
    }
    else
    {
        loadTexture(m_ncf4);
    }
    m_moveup ++;
    moveUp();
}
void Joueur::animationMoveDown()
{
    if(m_movedown % 8 == 0)
    {
        loadTexture(m_ncf0);
        m_movedown = 0;
    }
    else if(m_movedown % 8 == 1)
    {
        loadTexture(m_ncf1);
    }
    else if(m_movedown % 8 == 2)
    {
        loadTexture(m_ncf2);
    }
    else if(m_movedown % 8 == 3)
    {
        loadTexture(m_ncf3);
    }
    else if(m_movedown % 8 == 4)
    {
        loadTexture(m_ncf4);
    }
    else if(m_movedown % 8 == 5)
    {
        loadTexture(m_ncf5);
    }
    else if(m_movedown % 8 == 6)
    {
        loadTexture(m_ncf6);
    }
    else
    {
        loadTexture(m_ncf7);
    }
    m_movedown ++;
    moveDown();
}