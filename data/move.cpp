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

sf::Sprite animationHeros(int animationheros, sf::Sprite SHERO, sf::Texture *THERO11, sf::Texture *THERO12, sf::Texture *THERO13, sf::Texture *THERO14)
{
    if(animationheros % 4 == 0)
    {
        SHERO.setTexture(*THERO11);
    }
    else if(animationheros % 4 == 1)
    {
        SHERO.setTexture(*THERO12);
    }
    else if(animationheros % 4 == 2)
    {
        SHERO.setTexture(*THERO13);
    }
    else if(animationheros % 4 == 3)
    {
        SHERO.setTexture(*THERO14);
    }
    return SHERO;
}