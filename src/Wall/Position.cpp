/**
 * @file WallPublicPosition.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Wall.hpp"

void Wall::setPosition(sf::Vector2f POSITION) {
    this->m_SWall.setPosition(POSITION);
}

void Wall::setPositionVector(std::vector <sf::Vector2f> vector) {
    int size = 0;
    this->m_ListeSprite.clear();

    for (size = 0; size < vector.size(); size++) {
        m_ListeSprite.push_back(getSpritePosition(vector[size]));
    }
}
