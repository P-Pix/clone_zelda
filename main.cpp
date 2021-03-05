#include <iostream>
#include <SFML/Graphics.hpp>


sf::Texture open_texture(const char *NAME_IMAGE)
{
    sf:: Texture TEXTURE;
    if(!TEXTURE.loadFromFile(NAME_IMAGE))
    {
        std::cout << "error" << std::endl;
    }
    return TEXTURE;
}

sf::Vector2f move_direct()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return sf::Vector2f(-1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return sf::Vector2f(1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        return sf::Vector2f(0.f, -1.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        return sf::Vector2f(0.f, 1.f);
    }
    return sf::Vector2f(0.f, 0.f);
}

int main()
{
    const char *NAME_IMAGE = "skin/heros1.png";

    sf::Texture IMAGE_1;
    sf::Sprite SPRITE;
    //sf::Vector2f VECTOR = (1.f, 1.f);

    IMAGE_1 = open_texture(NAME_IMAGE);
    SPRITE.setTexture(IMAGE_1);

    sf::RenderWindow WINDOW(sf::VideoMode(1080, 720), "Zelda_Like");
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
        WINDOW.display();
    }
}