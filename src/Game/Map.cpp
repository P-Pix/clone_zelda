/**
 * @file GamePrivateMap.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Game.hpp"

void Game::setMapUpdate(void) {
    m_Map.generateMap();
    setBackground();
    makeListMonster();
}

void Game::switchMap(void) {
    if (m_Player.getPosition().x < 0) {
        m_Map.setMapLeft();
        setMapUpdate();
        m_Player.setPositionLeft();
    } else if (m_Player.getPosition().x > 1024) {
        m_Map.setMapRight();
        setMapUpdate();
        m_Player.setPositionRight();
    } else if (m_Player.getPosition().y < 64) {
        m_Map.setMapUp();
        setMapUpdate();
        m_Player.setPositionUp();
    } else if (m_Player.getPosition().y > 768) {
        m_Map.setMapDown();
        setMapUpdate();
        m_Player.setPositionDown();
    }
}

void Game::setBackground(void) {
    m_Bloc.setPositionVector(m_Map.getListPositionWall());
    m_Cavern.setPositionVector(m_Map.getListPositionSlad());
    m_Tree.setPositionVector(m_Map.getListPositionTree());
    m_Ground.setPositionVector(m_Map.getListPositionDust());
    m_OrangeTree.setPositionVector(m_Map.getListPositionOrangeTree());
    m_Water.setPositionVector(m_Map.getListPositionWater());
    m_WhiteTree.setPositionVector(m_Map.getListPositionWhiteTree());
    m_Bridge.setPositionVector(m_Map.getListPositionBridge());
    m_GreyGround.setPositionVector(m_Map.getListPositionGreyDust());
    m_Rock.setPositionVector(m_Map.getListPositionRock());
    m_RedRock.setPositionVector(m_Map.getListPositionRedRock());
    m_WhiteRock.setPositionVector(m_Map.getListPositionWhiteRock());
}

void Game::gainChest(void) {
    if (collideTwoSprite64x64(m_Player.getPosition(), m_Map.getGainSprite().getPosition())) {
        m_Player.setHeart(m_Map.getGainLife());
        m_Player.updateRubis(m_Map.getGainRubis());
        m_Map.gainIsGet();
    }
}