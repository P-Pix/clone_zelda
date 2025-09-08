/**
 * @file GamesWindow.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 1.1
 * @date 2021-05-31
 * @updated 2025-07-26
 * 
 * @copyright Copyright (c) 2021-2025
 * 
 */

#ifndef _GAMESWINDOW_HPP_
#define _GAMESWINDOW_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "Game.hpp"
#include "Config.hpp"
#include "Logger.hpp"

/// Window class and start the game
class GamesWindow {
private:
    const int m_windowwidth = Config::WINDOW_WIDTH;
    const int m_windowheight = Config::WINDOW_HEIGHT;

    std::unique_ptr<sf::RenderWindow> m_Window;
    sf::Event m_Event;
    sf::VideoMode m_VideoMode;

    Game m_Game;

    void pollEvent(void);

    void drawSprite(sf::Sprite sprite);

    void drawText(sf::Text Text);

    void drawVectorSprite(std::vector<sf::Sprite> vector);

    void drawVectorText(std::vector<sf::Text> vector);

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