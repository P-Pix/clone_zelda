/**
 * @file MonsterPublicMoove.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Monster.hpp"

void Monster::moove(void) {
    m_Sprite.move(m_Patern[m_moveaction]);
}

void Monster::recoilDown(void) {
    m_Sprite.move(sf::Vector2f(0.f, 64.f));
}

void Monster::recoilLeft(void) {
    m_Sprite.move(sf::Vector2f(-64.f, 0.f));
}

void Monster::recoilUp(void) {
    m_Sprite.move(sf::Vector2f(0.f, -64.f));
}

void Monster::recoilRight(void) {
    m_Sprite.move(sf::Vector2f(64.f, 0.f));
}

void Monster::nextPosition(void) {
    m_moveaction++;
    if (m_moveaction == m_Patern.size()) {
        m_Patern.clear();
        createPaternRelative();
        m_moveaction = 0;
    }
}