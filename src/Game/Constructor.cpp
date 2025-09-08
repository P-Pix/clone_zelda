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

Game::Game(void) : m_Tree(),
                   m_OrangeTree(m_orangetreename),
                   m_WhiteTree(m_whitetreename),
                   m_Water(m_watername),
                   m_Rock(m_rockname),
                   m_RedRock(m_redrockname),
                   m_WhiteRock(m_whiterockname),
                   m_Bloc(m_blocname),
                   
                   m_Ground(m_groundname),
                   m_GreyGround(m_greygroundname),
                   m_Bridge(m_bridgename),
                   m_Cavern(m_cavernname) {
    setMapUpdate();
}

Game::~Game(void) {

}