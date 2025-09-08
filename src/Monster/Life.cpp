/**
 * @file MonsterPublicLife.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/MonsterLegacy.hpp"

void Monster::setDamage(int power) {
    m_Heart.setDamage(power);
    if (m_Heart.getLife() == 0) {
        dropGain();
    }
}

void Monster::dropGain(void) {
    m_Gain.choseGain(m_Sprite.getPosition());
    m_Sprite = m_Gain.getSpriteGain();
}

void Monster::frameInvulnerable(void) {
    m_Heart.frameInvulnerable();
}