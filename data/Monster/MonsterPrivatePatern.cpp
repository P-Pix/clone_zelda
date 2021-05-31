/**
 * @file MonsterPrivatePatern.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Monster.hpp"

void Monster::createPaternStatic()
{
    for(int counter = 0; counter < 200; counter ++)
    {
        m_Patern.push_back(sf::Vector2f(-1.f, 0.f));
    }
    for(int counter = 0; counter < 200; counter ++)
    {
        m_Patern.push_back(sf::Vector2f(1.f, 0.f));
    }        
}
void Monster::createPaternRelative(sf::Vector2f target)
{
    m_Patern.clear();
    int positionx = m_Sprite.getPosition().x,
        positiony = m_Sprite.getPosition().y;
    if(m_turnxy)
    {
        if(target.x < positionx)
        {
            m_Patern.push_back(sf::Vector2f(-1.f, 0.f));
        }
        else if(target.x > positionx)
        {
            m_Patern.push_back(sf::Vector2f(1.f, 0.f));
        
        }
    }
    else
    {
        if(target.y < positiony)
        {
            m_Patern.push_back(sf::Vector2f(0.f, -1.f));
        }
        else if(target.y > positiony)
        {
            m_Patern.push_back(sf::Vector2f(0.f, 1.f));
        }
    }
    m_turnxy = !m_turnxy;
}