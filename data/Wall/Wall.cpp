/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Wall.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

// Constructor / Destructor

Wall::Wall()
{
    this -> m_SWall = loadSprite();
    //std::cout << "wall create " << this << std::endl;
}

Wall::Wall(const char *nametxt)
{
    this -> m_nametexture = nametxt;
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

std::vector<sf::Sprite> Wall::getListSprite()
{
    return m_ListeSprite;
}

// Function public

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

// Function private

sf::Sprite Wall::getSpritePosition(sf::Vector2f position)
{
    this -> m_SWall.setPosition(position);
    return m_SWall;
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
    if(!m_TWall.loadFromFile(m_nametexture))
    {
        std::cout << "error image " << m_nametexture << std::endl;
    }
}