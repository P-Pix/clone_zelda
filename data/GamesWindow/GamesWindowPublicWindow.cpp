/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::limitFramerate(int frame)
{
    this -> m_Window -> setFramerateLimit(frame);
}

void GamesWindow::updateWindow()
{
    this -> m_Window -> clear();
    modifMonster();
    allDrawWindow();
    this -> m_Window -> display();
}
void GamesWindow::verificationWindow()
{
    switchMap();
    canMove();
    swordAttack();
    collideMonster();
    if(m_Player.isInvulnerable())
    {
        m_Player.frameInvulnerable();
    }
    if(!m_Player.isAlive())
    {
        this -> m_Window -> close();
    }
}
void GamesWindow::controlWindow()
{
    this -> pollEvent();
}
