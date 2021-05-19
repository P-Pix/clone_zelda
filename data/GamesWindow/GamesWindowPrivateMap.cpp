/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

void GamesWindow::setMapUpdate()
{
    loadNewMap();
    setBackground();
}
void GamesWindow::switchMap()
{
    if(m_Player.getPosition().x < 0)
    {
        m_Map.setMapLeft();
        setMapUpdate();
        m_Player.setPositionLeft();
    }
    else if(m_Player.getPosition().x > 1088)
    {
        m_Map.setMapRight();
        setMapUpdate();
        m_Player.setPositionRight();
    }
    else if(m_Player.getPosition().y < 64)
    {
        m_Map.setMapUp();
        setMapUpdate();
        m_Player.setPositionUp();
    }
    if(m_Player.getPosition().y > 704)
    {
        m_Map.setMapDown();
        setMapUpdate();
        m_Player.setPositionDown();
    }
}
void GamesWindow::loadNewMap()
{
    m_Map.generateMap();
}
void GamesWindow::setBackground()
{
    m_Bloc.setPositionVector(m_Map.getListPositionWallInt());
    m_Cavern.setPositionVector(m_Map.getListPositionGroundInt());
    m_Tree.setPositionVector(m_Map.getListPositionWallExt());
    m_Ground.setPositionVector(m_Map.getListPositionGroundExt());
}