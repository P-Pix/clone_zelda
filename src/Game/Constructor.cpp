/**
 * @file Game.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Game.hpp"

Game::Game(void):   m_Bloc(m_blocname),
                    m_OrangeTree(m_orangetreename),
                    m_Water(m_watername),
                    m_WhiteTree(m_whitetreename),
                
                    m_Bridge(m_bridgename), 
                    m_GreyGround(m_greygroundname), 
                    m_Cavern(m_cavernname),
                    m_Ground(m_groundname)
{
    setMapUpdate();
}
Game::~Game(void)
{

}