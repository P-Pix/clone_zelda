#include "Heart.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

std::vector<sf::Sprite> Heart::getListSprite()
{
    return m_List;
}
sf::Sprite Heart::getSprite(int number)
{
    return m_List[number];
}