/**
 * @file WallAccessor.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../include/Wall.hpp"

sf::Sprite Wall::getSprite(void) {
    return m_SWall;
}

std::vector <sf::Sprite> Wall::getListSprite(void) {
    return m_ListeSprite;
}