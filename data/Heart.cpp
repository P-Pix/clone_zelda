#include "Heart.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#include <queue>
#include <list>
#include <vector>

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

std::vector<sf::Sprite> Heart::getListHeart()
{
    return m_list;
}

// Function public

void Heart::updateHeart(int life, int maxlife)
{
    int numberheart = life / 4;
    int lastheart = life % 4;
    int taillist = (maxlife / 4) + 1;
    this -> m_list.clear();
    std::vector<sf::Sprite> listelife(lastheart, m_S0Heart);
    std::vector<sf::Sprite> listeheart(taillist, m_S0Heart);
    std::vector<sf::Sprite>::iterator it;

    for(it = listeheart.begin(); it != listeheart.end(); it ++)
    {
        this -> m_list.push_back(m_S0Heart);
    }
    for(it = listeheart.begin(); it != listelife.end(); it ++)
    {
        this -> m_list.erase(it);
        this -> m_list.insert(it, m_S4Heart);
    }
    it++;
    if(lastheart == 1)
    {
        this -> m_list.erase(it);
        this -> m_list.insert(it, m_S1Heart);
    }
    else if(lastheart == 2)
    {
        this -> m_list.erase(it);
        this -> m_list.insert(it, m_S2Heart);
    }
    else if(lastheart == 3)
    {
        this -> m_list.erase(it);
        this -> m_list.insert(it, m_S3Heart);
    }
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