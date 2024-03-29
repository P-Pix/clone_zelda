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

#include "../../include/Game.hpp"

void Game::allDrawWindow(void) {
    m_vectorsprite.clear();
    m_vectortext.clear();

    // Up screen
    extractSpriteFromVector(m_Player.getListSpriteHeart()); // Life bar
    drawRubis(); // Rubis number

    // Element Immobile
    drawMap(); // Map
    //drawChest(); // Chest
    //drawChestGain();

    // Element Mobile
    m_vectorsprite.push_back(m_Mob1.getSprite()); // Monster
    m_vectorsprite.push_back(m_Player.getSprite()); // Player

    // Over all
    drawSword(); // Sword
}

void Game::drawChestGain(void) {
    m_vectorsprite.push_back(m_Map.getGainSprite());
}

void Game::drawChest(void) {
    if (m_Map.thereChest()) {
        m_vectorsprite.push_back(m_Map.getChestSprite());
    }
}

void Game::drawSword(void) {
    if (m_Sword.getExecution()) {
        m_Sword.animateAttack();
        m_vectorsprite.push_back(m_Sword.getSprite());
    }
}

void Game::drawRubis(void) {
    m_vectorsprite.push_back(m_Player.getLogoRubis());
    m_vectortext.push_back(m_Player.getRubisHundred());
    m_vectortext.push_back(m_Player.getRubisTen());
    m_vectortext.push_back(m_Player.getRubisUnit());
}

void Game::drawMap(void) {
    extractSpriteFromVector(m_Bloc.getListSprite());
    extractSpriteFromVector(m_Cavern.getListSprite());
    extractSpriteFromVector(m_Tree.getListSprite());
    extractSpriteFromVector(m_Ground.getListSprite());
    extractSpriteFromVector(m_OrangeTree.getListSprite());
    extractSpriteFromVector(m_Water.getListSprite());
    extractSpriteFromVector(m_WhiteTree.getListSprite());
    extractSpriteFromVector(m_Bridge.getListSprite());
    extractSpriteFromVector(m_GreyGround.getListSprite());
    extractSpriteFromVector(m_Rock.getListSprite());
    extractSpriteFromVector(m_RedRock.getListSprite());
    extractSpriteFromVector(m_WhiteRock.getListSprite());
}

void Game::extractSpriteFromVector(std::vector <sf::Sprite> vector) {
    for (int number = 0; number < vector.size(); number++) {
        m_vectorsprite.push_back(vector[number]);
    }
}