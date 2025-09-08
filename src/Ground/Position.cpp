/**
 * @file GroundPublicPosition.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Ground.hpp"

void Ground::setPosition(sf::Vector2f position) {
    this->m_Sprite.setPosition(position);
}

void Ground::setPositionVector(std::vector <sf::Vector2f> vector) {
    this->m_ListeSprite.clear();

    for (size_t size = 0; size < vector.size(); size++) {
        setPosition(vector[size]);
        m_ListeSprite.push_back(getSprite());
    }
}