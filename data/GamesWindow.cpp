#include <iostream>
#include <SFML/Graphics.hpp>
#include "GamesWindow.hpp"
#include "Joueur.hpp"

// Constructor / Destructor

GamesWindow::GamesWindow()
{
    this -> m_Window = nullptr;
    //((16* 64) + 64) * (11 * 64) = (1024 + 64) * 704
    this -> m_Window = new sf::RenderWindow(sf::VideoMode(1088, 704), "Zelda Like");
    std::cout << "window create " << this << std::endl;
}

GamesWindow::~GamesWindow()
{
    delete this -> m_Window;
    std::cout << "window destroy " << this << std::endl;
}

// Function private

void GamesWindow::drawElement(sf::Sprite SPRITE)
{
    this -> m_Window -> draw(SPRITE);
}

void GamesWindow::newPlayer()
{
    //m_Player = Joueur player;
}

// Accessor public

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}

sf::Sprite GamesWindow::getPlayerSprite()
{
    return m_Player.getSprite();
}

// Function public


void GamesWindow::setDrawing(sf::Sprite SPRITE)
{
    drawElement(SPRITE);
}

void GamesWindow::limitFramerate(int frame)
{
    this -> m_Window -> setFramerateLimit(frame);
}

void GamesWindow::clearWindow()
{
    this -> m_Window -> clear();
}

void GamesWindow::updateWindow()
{
    this -> m_Window -> display();
}

void GamesWindow::renderWindow()
{
    std::cout << "prout" << std::endl;
}

void GamesWindow::controlWindow()
{
    this -> pollEvent();
}

void GamesWindow::pollEvent()
{
    if(this -> m_Window -> pollEvent(this -> event))
    {
        if(this -> event.type == sf::Event::Closed)
        {
            this -> m_Window -> close();
        }
        else if (this -> event.type == sf::Event::KeyPressed)
        {
            if(this -> event.key.code == sf::Keyboard::Escape)
            {
                this -> m_Window -> close();
            }
            else if(this -> event.key.code == sf::Keyboard::Down)
            {
                m_Player.animationMoveDown();
            }
            else if(this -> event.key.code == sf::Keyboard::Up)
            {
                m_Player.animationMoveUp();
            }
            else if(this -> event.key.code == sf::Keyboard::Left)
            {
                m_Player.animationMoveLeft();
            }
            else if(this -> event.key.code == sf::Keyboard::Right)
            {
                m_Player.animationMoveRight();
            }
        }
    }
}