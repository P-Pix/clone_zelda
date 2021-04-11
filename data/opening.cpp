#include <iostream>
#include <SFML/Graphics.hpp>

sf::Texture openTexture(const char *NAME_IMAGE)
{
    sf:: Texture TEXTURE;
    if(!TEXTURE.loadFromFile(NAME_IMAGE))
    {
        std::cout << "error image " << NAME_IMAGE << std::endl;
    }
    return TEXTURE;
}

sf::Font openFont(const char *NAME_FONT)
{
    sf::Font font;
    if(!font.loadFromFile(NAME_FONT))
    {
        std::cout << "error font " << NAME_FONT << std::endl;
    }
    return font;
}

sf::Sprite loadSprite(const char *NAME, sf::Vector2f VECTOR, sf::Texture *TEXTURE)
{
    sf::Sprite SPRITE;
    *TEXTURE = openTexture(NAME);
    SPRITE.setTexture(*TEXTURE);
    SPRITE.move(VECTOR);
    return SPRITE;
}