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

void GamesWindow::limitFramerate(int frame)
{
    this -> m_Window -> setFramerateLimit(frame);
}

void GamesWindow::updateWindow(sf::Sprite SHEROS)
{
    this -> m_Window -> clear();
    drawElement(SHEROS);
    this -> m_Window -> display();
}

void GamesWindow::renderWindow()
{

}

void GamesWindow::controlWindow(sf::Sprite SHEROS)
{
    this -> pollEvent(SHEROS);
}

void GamesWindow::pollEvent(sf::Sprite SHEROS)
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
            else if(this -> event.key.code == sf::Keyboard::Down)
            {
                SHEROS.move(sf::Vector2f(1.f, 0.f));
                std::cout << "down arrow" << std::endl;
            }
            else if(this -> event.key.code == sf::Keyboard::Up)
            {
                SHEROS.move(sf::Vector2f(-1.f, 0.f));
                std::cout << "Up arrow" << std::endl;
            }
            else if(this -> event.key.code == sf::Keyboard::Left)
            {
                SHEROS.move(sf::Vector2f(0.f, -1.f));
                std::cout << "left arrow" << std::endl;
            }
            else if(this -> event.key.code == sf::Keyboard::Right)
            {
                SHEROS.move(sf::Vector2f(0.f, 1.f));
                std::cout << "right arrow" << std::endl;
            }
        }
    }
}