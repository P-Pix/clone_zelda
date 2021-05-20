/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::mooveMonster()
{
    m_Mob1.nextPosition();
    if(!previewCollide(m_Mob1.getPosition(), m_Mob1.getNextPosition()))
    {
        m_Mob1.moove();
    }
}
void GamesWindow::makeListMonster()
{
    m_listmob.clear();

    m_listmob.push_back(m_Mob1);
}