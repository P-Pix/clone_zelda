/**
 * @file GamesWindow.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__GAMESWINDOW__)
#define __GAMESWINDOW__

#include <SFML/Graphics.hpp>

#include "../Game/Game.hpp"

class GamesWindow
{
    public:

        // Constructor /Destructor
            GamesWindow(void);
            ~GamesWindow(void);

        // Accessor
            bool isRunning(void);

        // function
            void limitFramerate(int frame);
            void controlWindow(void);
            void updateWindow(void);
            void verificationWindow(void);

    private:
        //Variable
            const int   m_windowwidth   = 1024,
                        m_windowheight  = 768;

            // SFML
                sf::RenderWindow    *m_Window;
                sf::Event   m_Event;
                sf::VideoMode   m_VideoMode;

            // class
                Game m_Game;

        //Function
            // control
                void pollEvent(void);

            // draw
                void drawSprite(sf::Sprite sprite);
                void drawText(sf::Text Text);
                void drawVectorSprite(std::vector<sf::Sprite> vector);
                void drawVectorText(std::vector<sf::Text> vector);            
};

#endif