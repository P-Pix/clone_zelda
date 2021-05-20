#include "GamesWindow.hpp"


void GamesWindow::modifMonster()
{
    m_Mob1.moove();
}
void GamesWindow::makeListMonster()
{
    m_listmob.clear();

    m_listmob.push_back(m_Mob1);
}