/**
 * @file GamesWindowPrivateMap.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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
void GamesWindow::gainChest()
{
    if(collideTwoSprite64x64(m_Player.getPosition(), m_Map.getGainSprite().getPosition()))
    {
        m_Player.setHeart(m_Map.getGainLife());
        m_Player.updateRubis(m_Map.getGainRubis());
        m_Map.gainIsGet();
    }
}