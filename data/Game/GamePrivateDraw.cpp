/**
 * @file GamePrivateDraw.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Game.hpp"

void Game::allDrawWindow()
{
    m_vectorsprite.clear();
    m_vectortext.clear();
    
    // Up screen
    extractSpriteFromVector(m_Player.getListSpriteHeart()); // Life bar
    drawRubis(); // Rubis number

    // Element Immobile
    drawMap(); // Map
    drawChest(); // Chest
    drawChestGain();

    // Element Mobile
    m_vectorsprite.push_back(m_Mob1.getSprite()); // Monster
    m_vectorsprite.push_back(m_Player.getSprite()); // Player

    // Over all
    drawSword(); // Sword
}
void Game::drawChestGain()
{
    m_vectorsprite.push_back(m_Map.getGainSprite());
}
void Game::drawChest()
{
    if(m_Map.thereChest())
    {
        m_vectorsprite.push_back(m_Map.getChestSprite());
    }
}
void Game::drawSword()
{
    if(m_Sword.getExecution())
    {
        m_Sword.animateAttack();
        m_vectorsprite.push_back(m_Sword.getSprite());
    }
}
void Game::drawRubis()
{
    m_vectorsprite.push_back(m_Player.getLogoRubis());
    m_vectortext.push_back(m_Player.getRubisHundred());
    m_vectortext.push_back(m_Player.getRubisTen());
    m_vectortext.push_back(m_Player.getRubisUnit());
}
void Game::drawMap()
{
    extractSpriteFromVector(m_Bloc.getListSprite());
    extractSpriteFromVector(m_Cavern.getListSprite());
    extractSpriteFromVector(m_Tree.getListSprite());
    extractSpriteFromVector(m_Ground.getListSprite());
}

void Game::extractSpriteFromVector(std::vector<sf::Sprite> vector)
{
    for(int number = 0;  number < vector.size(); number ++)
    {
        m_vectorsprite.push_back(vector[number]);
    }
}