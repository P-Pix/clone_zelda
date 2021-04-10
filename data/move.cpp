#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f moveDirect()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return sf::Vector2f(-2.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return sf::Vector2f(2.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        return sf::Vector2f(0.f, -2.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        return sf::Vector2f(0.f, 2.f);
    }
    return sf::Vector2f(0.f, 0.f);
}