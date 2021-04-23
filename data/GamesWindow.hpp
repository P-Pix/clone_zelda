#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>
#include <iostream>

class GamesWindow
{
    public:
        
        // Constructor /Destructor
            GamesWindow();
            ~GamesWindow();
        
        // Accessor
            bool isRunning();

        // function
            void controlWindow();
            void updateWindow(sf::Sprite SPRITE);
            void renderWindow();
            void pollEvent();
    
    private:

        //Variable
            // iostream
                const int m_WindowWidth = 1088;
                const int m_WindowHeight = 704;

            // SFML            
                sf::RenderWindow *m_Window;
                sf::Event event;
                sf::VideoMode m_VideoMode;

        //Function
            void drawElement(sf::Sprite SPRITE);
};

#endif