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

#include "../../include/GamesWindow.hpp"

void GamesWindow::limitFramerate(int frame)
{
    this -> m_Window -> setFramerateLimit(frame);
}
void GamesWindow::updateWindow(void)
{
    this -> m_Window -> clear();
    drawVectorSprite(m_Game.getDrawingSprite());
    drawVectorText(m_Game.getDrawingText());
    this -> m_Window -> display();
}
void GamesWindow::verificationWindow(void)
{
    m_Game.executionGame();
    if(!m_Game.playerIsAlive())
    {
        this -> m_Window -> close();
    }
}
void GamesWindow::controlWindow(void)
{
    this -> pollEvent();
}
