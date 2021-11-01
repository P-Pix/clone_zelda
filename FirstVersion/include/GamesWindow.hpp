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

#ifndef _GAMESWINDOW_HPP_
#define _GAMESWINDOW_HPP_

#include <SFML/Graphics.hpp>

#include "Game.hpp"

/// Window class and start the game
class GamesWindow {
private:
    const int m_windowwidth = 1024,
            m_windowheight = 768;

    sf::RenderWindow *m_Window;
    sf::Event m_Event;
    sf::VideoMode m_VideoMode;

    Game m_Game;

    void pollEvent(void);

    void drawSprite(sf::Sprite sprite);

    void drawText(sf::Text Text);

    void drawVectorSprite(std::vector <sf::Sprite> vector);

    void drawVectorText(std::vector <sf::Text> vector);

public:
    ////////////////////////////////////////

    /// Default Constructor
    GamesWindow(void);

    /// Destructor
    ~GamesWindow(void);

    ////////////////////////////////////////

    /// \return true if the window is open
    bool isRunning(void);

    ////////////////////////////////////////

    /// Limit FPS
    /// \param frame FPS number
    void limitFramerate(int frame);

    ///
    void controlWindow(void);

    void updateWindow(void);

    void verificationWindow(void);
};

#endif