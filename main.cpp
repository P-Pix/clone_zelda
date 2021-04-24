#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/opening.cpp"
#include "data/move.cpp"
#include "data/screen.cpp"
#include "data/Monster.hpp"
#include "data/GamesWindow.hpp"
#include "data/Joueur.hpp"
#include "data/Wall.hpp"

int main()
{
    Monster M, M2, M3;

    const char 
        *BLOC = "skin/bloc.png",
        *TREE = "skin/tree.png",
        *CAVERN = "skin/cavern.png",
        *GROUND = "skin/ground.png",
        *COEUR = "skin/coeur.png",
        *QUARTCOEUR = "skin/quartcoeur.png",
        *VCOEUR = "skin/coeurvide.png",
        *FONT = "font/SuperLegendBoy.ttf";

    sf::Texture 
        TCAVERN,
        TGROUND,
        TCOEUR,
        TQCOEUR,
        TVCOEUR;

    sf::Sprite
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
    
    GamesWindow WINDOW;
    Joueur joueur;
    Wall tree(TREE), bloc(BLOC);

    // SPRITE
    SCAVERN = loadSprite(CAVERN, sf::Vector2f(64.f, 64.f), &TCAVERN);
    SGROUND = loadSprite(GROUND, sf::Vector2f(0.f, 64.f), &TGROUND);
    SCOEUR = loadSprite(COEUR, sf::Vector2f(0.f, 0.f), &TCOEUR);
    SQCOEUR = loadSprite(QUARTCOEUR, sf::Vector2f(0.f, 0.f), &TQCOEUR);
    SVCOEUR = loadSprite(VCOEUR, sf::Vector2f(0.f, 0.f), &TVCOEUR);

    FONT_8BIT = openFont(FONT);

    WINDOW.limitFramerate(4);

    std::cout << WINDOW.isRunning() << std::endl;
    while(WINDOW.isRunning())
    {
        WINDOW.controlWindow(joueur.sprite());
        /*
        WINDOW.updateWindow(bloc.sprite());
        WINDOW.updateWindow(tree.sprite());
        */
        WINDOW.updateWindow(joueur.sprite());
        /*
        //drawHeart(SVCOEUR, SQCOEUR, SCOEUR, boost, COEURPOSITION, &WINDOW);
        SHERO.move(moveDirect());
        SHERO = animationHeros(animationheros, SHERO, &THERO11, &THERO12, &THERO13, &THERO14);
        animationheros ++;
        WINDOW.draw(SCOEUR);
        WINDOW.draw(SCAVERN);
        WINDOW.draw(SGROUND);
        */
    }
    std::cout << WINDOW.isRunning() << std::endl;
    return 0;
}