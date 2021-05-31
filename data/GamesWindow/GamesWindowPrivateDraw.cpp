/**
 * @file GamesWindowPrivateDraw.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GamesWindow.hpp"

void GamesWindow::drawSprite(sf::Sprite sprite)
{
    this -> m_Window -> draw(sprite);
}
void GamesWindow::drawText(sf::Text text)
{
    this -> m_Window -> draw(text);
}
void GamesWindow::allDrawWindow()
{
    // Up screen
    drawVector(m_Player.getListSpriteHeart()); // Life bar
    drawRubis(); // Rubis number

    // Element Immobile
    drawMap(); // Map
    drawChest(); // Chest
    drawChestGain();

    // Element Mobile
    drawSprite(m_Mob1.getSprite()); // Monster
    drawSprite(m_Player.getSprite()); // Player

    // Over all
    drawSword(); // Sword
}
void GamesWindow::drawChestGain()
{
    drawSprite(m_Map.getGainSprite());
}
void GamesWindow::drawChest()
{
    if(m_Map.thereChest())
    {
        drawSprite(m_Map.getChestSprite());
    }
}
void GamesWindow::drawVector(std::vector<sf::Sprite> vector)
{
    for(int number = 0;  number < vector.size(); number ++)
    {
        drawSprite(vector[number]);
    }
}
void GamesWindow::drawSword()
{
    if(m_Sword.getExecution())
    {
        m_Sword.animateAttack();
        drawSprite(m_Sword.getSprite());
    }
}
void GamesWindow::drawRubis()
{
    drawSprite(m_Player.getLogoRubis());
    drawText(m_Player.getRubisHundred());
    drawText(m_Player.getRubisTen());
    drawText(m_Player.getRubisUnit());
}
void GamesWindow::drawMap()
{
    drawVector(m_Bloc.getListSprite());
    drawVector(m_Cavern.getListSprite());
    drawVector(m_Tree.getListSprite());
    drawVector(m_Ground.getListSprite());
}