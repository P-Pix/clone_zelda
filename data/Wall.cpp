#include "Wall.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

Wall::Wall()
{
    std::cout << "wall create " << this << std::endl;
    this -> m_SWall = loadSprite();
}

Wall::Wall(const char *nametxt)
{
    std::cout << "wall create " << this << std::endl;
    this -> m_NameTexture = nametxt;
    this -> m_SWall = loadSprite();
}

Wall::~Wall()
{
    std::cout << "Wall delete " << this << std::endl;
}

sf::Sprite Wall::getSprite()
{
    return m_SWall;
}

void Wall::setPosition(sf::Vector2f POSITION)
{
    this -> m_SWall.setPosition(POSITION);
}


sf::Sprite Wall::loadSprite()
{
    sf::Sprite SPRITE;
    loadTexture();
    SPRITE.setTexture(m_TWall);
    return SPRITE;
}

void Wall::loadTexture()
{
    if(!m_TWall.loadFromFile(m_NameTexture))
    {
        std::cout << "error image " << m_NameTexture << std::endl;
    }
}