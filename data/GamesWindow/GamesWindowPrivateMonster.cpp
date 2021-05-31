/**
 * @file GamesWindowPrivateMonster.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GamesWindow.hpp"

void GamesWindow::mooveMonster()
{
    m_Mob1.nextPosition();
    if(!previewCollide(m_Mob1.getPosition(), m_Mob1.getNextPosition()) && m_Mob1.isAlive())
    {
        m_Mob1.moove();
    }
}
void GamesWindow::makeListMonster()
{
    m_listmob.clear();

    m_listmob.push_back(m_Mob1);
}