/**
 * @file ChestAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Chest.hpp"

sf::Sprite Chest::getSprite(void) {
    return m_Sprite;
}

bool Chest::getChest(void) {
    return m_spawnchest;
}

int Chest::getValorLife(void) {
    return m_Gain.getValorGainLife();
}

int Chest::getValorRubis(void) {
    return m_Gain.getValorGainRubis();
}

sf::Sprite Chest::getSpriteGain(void) {
    return m_Gain.getSpriteGain();
}