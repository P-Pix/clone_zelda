
#include "Heart.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void Heart::updateHeart(int life, int maxlife)
{
    int numberheart = life / 4,
        lastheart = life % 4,
        taillist = maxlife / 4,
        positionx = 0,
        positiony = 0,
        size = 0;

    this -> m_List.clear();

    std::vector<sf::Sprite> listelife(numberheart, m_S0Heart),
                            listeheart(taillist, m_S0Heart);

    // full heart
    for(size = 0; size < listelife.size(); size ++)
    {
        this -> m_List.push_back(setSpritePosition(m_S4Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
        positionx ++;
        if(positionx == 10)
        {
            positionx = 0;
            positiony ++;
        }
    }
    
    // quart heart
    if(lastheart == 1)
    {
        this -> m_List.push_back(setSpritePosition(m_S1Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
    }
    else if(lastheart == 2)
    {
        this -> m_List.push_back(setSpritePosition(m_S2Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
    }
    else if(lastheart == 3)
    {
        this -> m_List.push_back(setSpritePosition(m_S3Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
    }

    // empty heart
    for(size = size; size < listeheart.size(); size ++)
    {
        this -> m_List.push_back(setSpritePosition(m_S0Heart, sf::Vector2f(positionx * 32.f, positiony * 32.f)));
        positionx ++;
        if(positionx == 10)
        {
            positionx = 0;
            positiony ++;
        }
    }
}
void Heart::setPosition(sf::Sprite sprite, sf::Vector2f position)
{
    sprite.setPosition(position);
}