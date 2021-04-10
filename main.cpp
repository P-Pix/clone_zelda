#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/opening.cpp"
#include "data/move.cpp"

int main()
{
    const char 
        *HERO = "skin/heros1.png", 
        *BLOC = "skin/bloc.png",
        *TREE = "skin/tree.png",
        *CAVERN = "skin/cavern.png",
        *GROUND = "skin/ground.png",
        *FONT = "font/SuperLegendBoy.ttf";

    sf::Texture THERO, TBLOC, TTREE, TCAVERN, TGROUND;
    sf::Sprite SHERO, SBLOC, STREE, SGROUND, SCAVERN;
    sf::Font FONT_LEMON, FONT_8BIT;
    sf::Text TEXTE("Hello SFML", FONT_8BIT, 150); 

    //(16* 64) * (11 * 64) = 1024 * 704
    sf::RenderWindow WINDOW(sf::VideoMode(1024, 704), "Zelda_Like"); 

    // Hero def
    THERO = openTexture(HERO);
    SHERO.setTexture(THERO);
    SHERO.setScale(2, 2);

    // Bloc def
    TBLOC = openTexture(BLOC);
    SBLOC.setTexture(TBLOC);
    SBLOC.move(sf::Vector2f(64.f, 64.f));

    // Tree def
    TTREE = openTexture(TREE);
    STREE.setTexture(TTREE);
    STREE.move(sf::Vector2f(0.f, 64.f));

    // Cavern def
    TCAVERN = openTexture(CAVERN);
    SCAVERN.setTexture(TCAVERN);
    SCAVERN.move(sf::Vector2f(64.f, 0.f));

    // Ground def
    TGROUND = openTexture(GROUND);
    SGROUND.setTexture(TGROUND);
    SGROUND.move(sf::Vector2f(0.f, 0.f));

    FONT_8BIT = openFont(FONT);

    WINDOW.setFramerateLimit(120);

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
        SHERO.move(moveDirect());
        WINDOW.clear();
        WINDOW.draw(SBLOC);
        WINDOW.draw(STREE);
        WINDOW.draw(SCAVERN);
        WINDOW.draw(SGROUND);
        WINDOW.draw(SHERO);
        //WINDOW.draw(TEXTE);
        WINDOW.display();
    }
}