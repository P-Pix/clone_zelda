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
void Monster::createPaternRelative()
{
    int random = std::rand() % 4;
    if(random == 0)
    {
        for(int x = 0; x < 64; x ++)
        {
            m_Patern.push_back(sf::Vector2f(0.f, 1.f));
        }
    }
    else if(random == 1)
    {
        for(int x = 0; x < 64; x ++)
        {
            m_Patern.push_back(sf::Vector2f(0.f, -1.f));
        }
    }
    else if(random == 2)
    {
        for(int x = 0; x < 64; x ++)
        {
            m_Patern.push_back(sf::Vector2f(1.f, 0.f));
        }
    }
    else if(random == 3)
    {
        for(int x = 0; x < 64; x ++)
        {
            m_Patern.push_back(sf::Vector2f(-1.f, 0.f));
        }
    }
}