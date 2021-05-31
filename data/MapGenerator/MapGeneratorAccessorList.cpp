/**
 * @file MapGeneratorAccessorList.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MapGenerator.hpp"

std::vector<sf::Vector2f> MapGenerator::getListPositionWallExt()
{
    return m_WallExt;
}
std::vector<sf::Vector2f> MapGenerator::getListPositionGroundExt()
{
    return m_GroundExt;
}
std::vector<sf::Vector2f> MapGenerator::getListPositionWallInt()
{
    return m_WallInt;
}
std::vector<sf::Vector2f> MapGenerator::getListPositionGroundInt()
{
    return m_GroundInt;
}
std::vector<std::vector<char>> MapGenerator::getMap()
{
    return m_map;
}