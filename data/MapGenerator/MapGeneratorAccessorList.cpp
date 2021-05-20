/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

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