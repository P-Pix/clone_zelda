#include "Monster.hpp"

void Monster::createPatern()
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