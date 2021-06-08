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

std::vector<sf::Vector2f> MapGenerator::getListPositionWallExt(void)
{
    return m_WallExt;
}
std::vector<sf::Vector2f> MapGenerator::getListPositionGroundExt(void)
{
    return m_GroundExt;
}
std::vector<sf::Vector2f> MapGenerator::getListPositionWallInt(void)
{
    return m_WallInt;
}
std::vector<sf::Vector2f> MapGenerator::getListPositionGroundInt(void)
{
    return m_GroundInt;
}
std::vector<std::vector<char>> MapGenerator::getMap(void)
{
    return m_map;
}