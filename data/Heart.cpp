#include "Heart.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

// Consructor / Destructor

Heart::Heart()
{
    loadSprite(m_T0Heart, m_S0Heart, m_name0);
    loadSprite(m_T1Heart, m_S1Heart, m_name1);
    loadSprite(m_T2Heart, m_S2Heart, m_name2);
    loadSprite(m_T3Heart, m_S3Heart, m_name3);
    loadSprite(m_T4Heart, m_S4Heart, m_name4);
    std::cout << "heart create " << this << std::endl;
}

Heart::~Heart()
{
    std::cout << "heart delete " << this << std::endl;
}

// Accessor

std::list<sf::Sprite> Heart::getListHeart()
{
    return m_list;
}

// Function public

void Heart::updateHeart(int life, int maxlife)
{
    int numberheart = life / 4;
    int lastheart = life % 4;
    this -> m_list[(maxlife / 4) + 1];
    std::list<sf::Sprite> listeheart[(maxlife / 4) + 1];
    for(int counter = 0; counter < maxlife / 4; counter ++)
    {
        this -> m_list[counter] = m_S0Heart;
    }
    for(int counter = 0; counter < numberheart; counter ++)
    {
        m_list[counter] = m_S4Heart;
    }
    if(lastheart == 1)
    {
        m_list[numberheart] = m_S1Heart;
    }
    else if(lastheart == 2)
    {
        m_list[numberheart] = m_S2Heart;
    }
    else if(lastheart == 3)
    {
        m_list[numberheart] = m_S3Heart;
    }
    m_list[] = listeheart;
}

// Function private

void Heart::loadSprite(sf::Texture texture, sf::Sprite sprite, const char *name)
{
    loadTexture(texture, name);
    sprite.setTexture(texture);
}

void Heart::loadTexture(sf::Texture texture, const char *name)
{
    if(!texture.loadFromFile(name))
    {
        std::cout << "error image " << name << std::endl;
    }
}