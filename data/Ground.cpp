#include "Ground.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Constructor / Destructor

Ground::Ground()
{
    initSprite();
    //std::cout << "Ground create " << this << std::endl;
}

Ground::Ground(const char *name)
{
    this -> m_Name = name;
    initSprite();
    //std::cout << "Ground create " << this << std::endl;
}

Ground::~Ground()
{
    //std::cout << "Ground deete " << this << std::endl;
}

// Accessor

std::vector<sf::Sprite> Ground::getListSprite()
{
    return m_ListeSprite;
}

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

void Ground::setPositionVector(std::vector<sf::Vector2f> vector)
{
    int size = 0;
    this -> m_ListeSprite.clear();

    for(size = 0; size < vector.size(); size ++)
    {
        m_ListeSprite.push_back(getSpritePosition(vector[size]));
    }
}

// Function private

sf::Sprite Ground::getSpritePosition(sf::Vector2f position)
{
    this -> m_Sprite.setPosition(position);
    return m_Sprite;
}

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