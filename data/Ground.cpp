#include "Ground.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor / Destructor

Ground::Ground()
{
    initSprite();
    std::cout << "Ground create " << this << std::endl;
}

Ground::Ground(const char *name)
{
    this -> m_Name = name;
    initSprite();
    std::cout << "Ground create " << this << std::endl;
}

Ground::~Ground()
{
    std::cout << "Ground deete " << this << std::endl;
}

// Accessor

sf::Sprite Ground::getSprite()
{
    return m_Sprite;
}

Ground* Ground::getAdress()
{
    return this;
}

// Function public

void Ground::setPosition(sf::Vector2f POSITION)
{
    this -> m_Sprite.setPosition(POSITION);
}

// Function private

void Ground::initSprite()
{
    loadTexture();
    loadSprite();
}

void Ground::loadSprite()
{
    m_Sprite.setTexture(m_Texture);
}

void Ground::loadTexture()
{
    if(!m_Texture.loadFromFile(m_Name))
    {
        std::cout << "error image " << m_Name << std::endl;
    }
}