#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/Monster.hpp"
#include "data/GamesWindow.hpp"
#include "data/Wall.hpp"
#include "data/Ground.hpp"

int main()
{

    const char 
        *BLOC = "skin/bloc.png",
        *CAVERN = "skin/cavern.png",
        *FONT = "font/SuperLegendBoy.ttf";
    
    sf::Vector2f COEURPOSITION[4] = 
    {
        sf::Vector2f(0.f, 0.f),
        sf::Vector2f(0.f, 16.f),
        sf::Vector2f(16.f, 16.f),
        sf::Vector2f(16.f, 0.f)
    };

    sf::Font FONT_8BIT;
    sf::Text TEXTE("Hello SFML", FONT_8BIT, 150);
    
    Monster M, M2, M3;
    GamesWindow WINDOW;
    Wall tree, bloc(BLOC); // de base l'image load est tree
    Ground ground, cavern(CAVERN); // de base l'image load est ground

    // SPRITE
    //FONT_8BIT = openFont(FONT);

    WINDOW.limitFramerate(60);
    bloc.setPosition(sf::Vector2f(64.f, 0.f));
    tree.setPosition(sf::Vector2f(128.f, 0.f));
    ground.setPosition(sf::Vector2f(0.f, 64.f));
    cavern.setPosition(sf::Vector2f(0.f, 128.f));

    std::cout << WINDOW.isRunning() << std::endl;
    while(WINDOW.isRunning())
    {
        // Controls

        WINDOW.controlWindow();

        // Update Window

        WINDOW.modifiHeart();
        WINDOW.clearWindow();
        WINDOW.drawLife();
        WINDOW.setDrawing(bloc.getSprite());
        WINDOW.setDrawing(tree.getSprite());
        WINDOW.setDrawing(ground.getSprite());
        WINDOW.setDrawing(cavern.getSprite());
        WINDOW.setDrawing(WINDOW.getPlayerSprite());
        WINDOW.updateWindow();
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