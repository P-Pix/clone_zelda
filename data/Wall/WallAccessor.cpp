#include "Wall.hpp"

sf::Sprite Wall::getSprite()
{
    return m_SWall;
}

std::vector<sf::Sprite> Wall::getListSprite()
{
    return m_ListeSprite;
}