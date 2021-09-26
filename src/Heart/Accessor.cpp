/**
 * @file HeartAccessorSprite.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Heart.hpp"

std::vector <sf::Sprite> Heart::getListSprite(void) {
    return m_List;
}

sf::Sprite Heart::getSprite(int number) {
    return m_List[number];
}

int Heart::getLife(void) {
    return m_life;
}

int Heart::getMaxLife(void) {
    return m_maxlife;
}

bool Heart::isInvulnerable(void) {
    return m_invulnerable;
}

bool Heart::isAlive(void) {
    return m_alive;
}