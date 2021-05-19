/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"

void Joueur::animationMoveRight()
{
    if(m_moveright % 32 == 0)
    {
        loadTexture(m_ncf0);
        m_moveright = 0;
    }
    else if(m_moveright % 32 == 4)
    {
        loadTexture(m_ncf1);
    }
    else if(m_moveright % 32 == 8)
    {
        loadTexture(m_ncf2);
    }
    else if(m_moveright % 32 == 12)
    {
        loadTexture(m_ncf3);
    }
    else if(m_moveright % 32 == 16)
    {
        loadTexture(m_ncf4);
    }
    else if(m_moveright % 32 == 20)
    {
        loadTexture(m_ncf5);
    }
    else if(m_moveright % 32 == 24)
    {
        loadTexture(m_ncf6);
    }
    else if(m_moveright % 32 == 28)
    {
        loadTexture(m_ncf7);
    }
    m_moveright ++;
    moveRight();
}
void Joueur::animationMoveLeft()
{
    if(m_moveleft % 32 == 0)
    {
        loadTexture(m_ncf0);
        m_moveleft = 0;
    }
    else if(m_moveleft % 32 == 4)
    {
        loadTexture(m_ncf1);
    }
    else if(m_moveleft % 32 == 8)
    {
        loadTexture(m_ncf2);
    }
    else if(m_moveleft % 32 == 12)
    {
        loadTexture(m_ncf3);
    }
    else if(m_moveleft % 32 == 16)
    {
        loadTexture(m_ncf4);
    }
    else if(m_moveleft % 32 == 20)
    {
        loadTexture(m_ncf5);
    }
    else if(m_moveleft % 32 == 24)
    {
        loadTexture(m_ncf6);
    }
    else if(m_moveleft % 32 == 28)
    {
        loadTexture(m_ncf7);
    }
    m_moveleft ++;
    moveLeft();
}
void Joueur::animationMoveUp()
{
    if(m_moveup % 32 == 0)
    {
        loadTexture(m_ncf0);
        m_moveup = 0;
    }
    else if(m_moveup % 32 == 4)
    {
        loadTexture(m_ncf1);
    }
    else if(m_moveup % 32 == 8)
    {
        loadTexture(m_ncf2);
    }
    else if(m_moveup % 32 == 12)
    {
        loadTexture(m_ncf3);
    }
    else if(m_moveup % 32 == 16)
    {
        loadTexture(m_ncf4);
    }
    else if(m_moveup % 32 == 20)
    {
        loadTexture(m_ncf5);
    }
    else if(m_moveup % 32 == 24)
    {
        loadTexture(m_ncf6);
    }
    else if(m_moveup % 32 == 28)
    {
        loadTexture(m_ncf7);
    }
    m_moveup ++;
    moveUp();
}
void Joueur::animationMoveDown()
{
    if(m_movedown % 32 == 0)
    {
        loadTexture(m_ncf0);
        m_movedown = 0;
    }
    else if(m_movedown % 32 == 4)
    {
        loadTexture(m_ncf1);
    }
    else if(m_movedown % 32 == 8)
    {
        loadTexture(m_ncf2);
    }
    else if(m_movedown % 32 == 12)
    {
        loadTexture(m_ncf3);
    }
    else if(m_movedown % 32 == 16)
    {
        loadTexture(m_ncf4);
    }
    else if(m_movedown % 32 == 20)
    {
        loadTexture(m_ncf5);
    }
    else if(m_movedown % 32 == 24)
    {
        loadTexture(m_ncf6);
    }
    else if(m_movedown % 32 == 28)
    {
        loadTexture(m_ncf7);
    }
    m_movedown ++;
    moveDown();
}