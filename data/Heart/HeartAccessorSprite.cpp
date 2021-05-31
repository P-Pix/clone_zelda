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

#include "Heart.hpp"

std::vector<sf::Sprite> Heart::getListSprite()
{
    return m_List;
}
sf::Sprite Heart::getSprite(int number)
{
    return m_List[number];
}