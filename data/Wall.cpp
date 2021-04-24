#include "Wall.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

Wall::Wall()
{

}

Wall::Wall(const char *nametxt)
{
    this -> m_NameTexture = nametxt;
    this -> m_SWall = loadSprite();
}

Wall::~Wall()
{

}

sf::Sprite Wall::sprite()
{
    return m_SWall;
}

sf::Sprite Wall::loadSprite()
{
    sf::Sprite SPRITE;
    loadTexture(m_NameTexture);
    SPRITE.setTexture(m_TWall);
    return SPRITE;
}

void Wall::loadTexture(const char *NAME)
{
    if(!m_TWall.loadFromFile(NAME))
    {
        std::cout << "error image " << NAME << std::endl;
    }
}