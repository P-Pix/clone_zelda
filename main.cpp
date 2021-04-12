#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/opening.cpp"
#include "data/move.cpp"
#include "data/screen.cpp"

int main()
{
    const char 
        *HERO = "skin/heros1.png", 
        *BLOC = "skin/bloc.png",
        *TREE = "skin/tree.png",
        *CAVERN = "skin/cavern.png",
        *GROUND = "skin/ground.png",
        *COEUR = "skin/coeur.png",
        *QUARTCOEUR = "skin/quartcoeur.png",
        *VCOEUR = "skin/coeurvide.png",
        *FONT = "font/SuperLegendBoy.ttf";
    
    int boost = 1;

    sf::Texture 
        THERO,
        TBLOC,
        TTREE,
        TCAVERN,
        TGROUND,
        TCOEUR,
        TQCOEUR,
        TVCOEUR;

    sf::Sprite 
        SHERO,
        SBLOC,
        STREE,
        SGROUND,
        SCAVERN,
        SCOEUR,
        SQCOEUR,
        SVCOEUR;

    sf::Vector2f COEURPOSITION[4] = 
    {
        sf::Vector2f(0.f, 0.f),
        sf::Vector2f(0.f, 16.f),
        sf::Vector2f(16.f, 16.f),
        sf::Vector2f(16.f, 0.f)
    };

    sf::Font FONT_8BIT;
    sf::Text TEXTE("Hello SFML", FONT_8BIT, 150);

    //((16* 64) + 64) * (11 * 64) = (1024 + 64) * 704
    sf::RenderWindow WINDOW(sf::VideoMode(1088, 704), "Zelda_Like"); 
    sf::RenderTarget TWINDOW.getSize(WINDOW);

    // SPRITE
    SHERO = loadSprite(HERO, sf::Vector2f(128.f, 128.f), &THERO);
    SHERO.setScale(2, 2);
    SBLOC = loadSprite(BLOC, sf::Vector2f(64.f, 128.f), &TBLOC);
    STREE = loadSprite(TREE, sf::Vector2f(0.f, 128.f), &TTREE);
    SCAVERN = loadSprite(CAVERN, sf::Vector2f(64.f, 64.f), &TCAVERN);
    SGROUND = loadSprite(GROUND, sf::Vector2f(0.f, 64.f), &TGROUND);
    SCOEUR = loadSprite(COEUR, sf::Vector2f(0.f, 0.f), &TCOEUR);
    SQCOEUR = loadSprite(QUARTCOEUR, sf::Vector2f(0.f, 0.f), &TQCOEUR);
    SVCOEUR = loadSprite(VCOEUR, sf::Vector2f(0.f, 0.f), &TVCOEUR);

    /* setPosition */


    FONT_8BIT = openFont(FONT);

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
        drawHeart(SVCOEUR, SQCOEUR, SCOEUR, boost, COEURPOSITION, sf::RenderTarget WINDOW.getSize());
        SHERO.move(moveDirect());
        WINDOW.draw(SCOEUR);
        WINDOW.draw(SBLOC);
        WINDOW.draw(STREE);
        WINDOW.draw(SCAVERN);
        WINDOW.draw(SGROUND);
        WINDOW.draw(SHERO);
        WINDOW.display();
    }
}