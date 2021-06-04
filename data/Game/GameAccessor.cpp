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

std::vector<sf::Sprite> Game::getDrawingSprite()
{
    return m_vectorsprite;
}
std::vector<sf::Text> Game::getDrawingText()
{
    return m_vectortext;
}
bool Game::playerIsAlive()
{
    return m_Player.isAlive();
}