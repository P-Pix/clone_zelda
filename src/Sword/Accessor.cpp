/**
 * @file SwordAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Sword.hpp"

sf::Sprite Sword::getSprite(void) {
    return m_Sprite;
}

sf::Vector2f Sword::getPosition(void) {
    return m_Sprite.getPosition();
}

int Sword::getPower(void) {
    return m_power;
}

bool Sword::getExecution(void) {
    return m_aniamtionexe;
}

bool Sword::getAttackUp(void) {
    return m_animationup;
}

bool Sword::getAttackLeft(void) {
    return m_animationleft;
}

bool Sword::getAttackRight(void) {
    return m_animationright;
}

bool Sword::getAttackDown(void) {
    return m_animationdown;
}