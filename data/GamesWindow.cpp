#include <iostream>
#include <SFML/Graphics.hpp>
#include "GamesWindow.hpp"

// Constructor / Destructor

GamesWindow::GamesWindow()
{
    this -> m_Window = nullptr;
    this -> m_Window = new sf::RenderWindow(sf::VideoMode(1088, 704), "Zelda Like");
    std::cout << "window create" << std::endl; 
}

GamesWindow::~GamesWindow()
{
    delete this -> m_Window;
    std::cout << "window destroy" << std::endl;
}

// Function private

void GamesWindow::drawElement(sf::Sprite SPRITE)
{
    this -> m_Window -> draw(SPRITE);
}

// Accessor public

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}

// Function public

void GamesWindow::updateWindow(sf::Sprite SPRITE)
{
    this -> m_Window -> clear();
    drawElement(SPRITE);
    this -> m_Window -> display();
}

void GamesWindow::renderWindow()
{

}

void GamesWindow::controlWindow()
{
    this -> pollEvent();
}

void GamesWindow::pollEvent()
{
    while(this -> m_Window -> pollEvent(this -> event))
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
        }
    }
}