#include "Wall.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

Wall::Wall()
{
    this -> m_SWall = loadSprite();
    //std::cout << "wall create " << this << std::endl;
}

Wall::Wall(const char *nametxt)
{
    this -> m_NameTexture = nametxt;
    this -> m_SWall = loadSprite();
    //std::cout << "wall create " << this << std::endl;
}

Wall::~Wall()
{
    //std::cout << "Wall delete " << this << std::endl;
}

// Accessor

sf::Sprite Wall::getSprite()
{
    return m_SWall;
}

// Function public

void Wall::setPosition(sf::Vector2f POSITION)
{
    this -> m_SWall.setPosition(POSITION);
}

// Function private

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