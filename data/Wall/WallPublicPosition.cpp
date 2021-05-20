#include "Wall.hpp"

void Wall::setPosition(sf::Vector2f POSITION)
{
    this -> m_SWall.setPosition(POSITION);
}

void Wall::setPositionVector(std::vector<sf::Vector2f> vector)
{
    int size = 0;
    this -> m_ListeSprite.clear();

    for(size = 0; size < vector.size(); size ++)
    {
        m_ListeSprite.push_back(getSpritePosition(vector[size]));
    }
}
