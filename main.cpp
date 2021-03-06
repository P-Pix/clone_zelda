#include <iostream>
#include <SFML/Graphics.hpp>


sf::Texture open_texture(const char *NAME_IMAGE)
{
    sf:: Texture TEXTURE;
    if(!TEXTURE.loadFromFile(NAME_IMAGE))
    {
        std::cout << "error image " << NAME_IMAGE << std::endl;
    }
    return TEXTURE;
}

sf::Vector2f move_direct()
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

sf::Font open_font(const char *NAME_FONT)
{
    sf::Font font;
    if(!font.loadFromFile(NAME_FONT))
    {
        std::cout << "error font " << NAME_FONT << std::endl;
    }
    return font;
}

int main()
{
    const char *NAME_IMAGE = "skin/heros1.png";
    const char *NAME_FONT_2 = "font/SuperLegendBoy.ttf";

    sf::Texture IMAGE_1;
    sf::Sprite SPRITE;
    sf::Font FONT_LEMON, FONT_8BIT;
    sf::Text TEXTE("Hello SFML", FONT_8BIT, 150); 
    sf::RenderWindow WINDOW(sf::VideoMode(1080, 720), "Zelda_Like");
    //sf::Vector2f VECTOR = (1.f, 1.f);

    IMAGE_1 = open_texture(NAME_IMAGE);
    SPRITE.setTexture(IMAGE_1);

    FONT_8BIT = open_font(NAME_FONT_2);

    WINDOW.setFramerateLimit(60);

    while(WINDOW.isOpen())
    {
        sf::Event event;
        while(WINDOW.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                WINDOW.close();
            }
        }
        SPRITE.move(move_direct());
        WINDOW.clear();
        WINDOW.draw(SPRITE);
        //WINDOW.draw(TEXTE);
        WINDOW.display();
    }
}