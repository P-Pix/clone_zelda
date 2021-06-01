/**
 * @file GamesWindowPublicWindow.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GamesWindow.hpp"

void GamesWindow::limitFramerate(int frame)
{
    this -> m_Window -> setFramerateLimit(frame);
}

void GamesWindow::updateWindow()
{
    this -> m_Window -> clear();
    mooveMonster();
    allDrawWindow();
    this -> m_Window -> display();
}
void GamesWindow::verificationWindow()
{
    switchMap();
    swordAttack();
    collideMonster();
    gainChest();
    if(m_Player.isInvulnerable())
    {
        m_Player.frameInvulnerable();
    }
    if(!m_Player.isAlive())
    {
        this -> m_Window -> close();
    }
    if(m_Mob1.isInvulnerable())
    {
        m_Mob1.frameInvulnerable();
    }
}
void GamesWindow::controlWindow()
{
    this -> pollEvent();
}
