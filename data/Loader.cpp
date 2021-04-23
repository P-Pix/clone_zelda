#include "Loader.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Loader::Loader()
{

}

Loader::~Loader()
{
    
}

sf::Sprite Loader::loadSprite(const char *NAME, sf::Vector2f VECTOR, sf::Texture *TEXTURE);
{
    *TEXTURE = openTexture(NAME);
    m_Sprite.setTexture(*TEXTURE);
    m_Sprite.move(VECTOR);
    return m_Sprite;
}