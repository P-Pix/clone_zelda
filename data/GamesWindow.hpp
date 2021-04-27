#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Joueur.hpp"

class GamesWindow
{
    public:
        
        // Constructor /Destructor
            GamesWindow();
            ~GamesWindow();
        
        // Accessor
            bool isRunning();
            sf::Sprite getPlayerSprite();

        // function
            void controlWindow();
            void clearWindow();
            void updateWindow();
            void renderWindow();
            void limitFramerate(int frame);
            void setDrawing(sf::Sprite SPRITE);
    
    private:

        //Variable
            // iostream
                const int m_WindowWidth = 1088;
                const int m_WindowHeight = 704;

            // SFML            
                sf::RenderWindow *m_Window;
                sf::Event event;
                sf::VideoMode m_VideoMode;

            // Joueur
                Joueur m_Player;

        //Function
            void drawElement(sf::Sprite SPRITE);
            void pollEvent();
            void newPlayer();
};

#endif