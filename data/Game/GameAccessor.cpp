/**
 * @file GameAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Game.hpp"

std::vector<sf::Sprite> Game::getDrawingSprite(void)
{
    return m_vectorsprite;
}
std::vector<sf::Text> Game::getDrawingText(void)
{
    return m_vectortext;
}
bool Game::playerIsAlive(void)
{
    return m_Player.isAlive();
}