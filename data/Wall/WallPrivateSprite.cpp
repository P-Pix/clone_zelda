#include "Wall.hpp"

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