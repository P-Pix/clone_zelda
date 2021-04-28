#include <iostream>
#include <SFML/Graphics.hpp>
#include "GamesWindow.hpp"
#include "Joueur.hpp"
#include "Heart.hpp"
#include <vector>

// Constructor / Destructor

GamesWindow::GamesWindow(): m_bloc(m_Bloc), m_cavern(m_Cavern)
{
    this -> m_Window = nullptr;
    //((16* 64) + 64) * (11 * 64) = (1024 + 64) * 704
    this -> m_Window = new sf::RenderWindow(sf::VideoMode(1088, 704), "Zelda Like");
    //std::cout << "window create " << this << std::endl;
}

GamesWindow::~GamesWindow()
{
    //std::cout << "window delete " << this << std::endl;
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

void GamesWindow::updateWindow()
{
    this -> m_Window -> clear();
    modifiHeart();
    allDrawWindow();
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

// Function private

void GamesWindow::setDrawing(sf::Sprite SPRITE)
{
    drawElement(SPRITE);
}

void GamesWindow::modifiHeart()
{
    this -> m_Heart.updateHeart(m_Player.getLife(), m_Player.getMaxLife());
}

void GamesWindow::drawElement(sf::Sprite SPRITE)
{
    this -> m_Window -> draw(SPRITE);
}

void GamesWindow::setPosition()
{
    m_bloc.setPosition(sf::Vector2f(0.f, 64.f));
    m_tree.setPosition(sf::Vector2f(0.f, 128.f));
    m_ground.setPosition(sf::Vector2f(64.f, 64.f));
    m_cavern.setPosition(sf::Vector2f(64.f, 128.f));
}

void GamesWindow::allDrawWindow()
{
    drawLife();
    setPosition();
    setDrawing(m_bloc.getSprite());
    setDrawing(m_tree.getSprite());
    setDrawing(m_ground.getSprite());
    setDrawing(m_cavern.getSprite());
    setDrawing(m_Player.getSprite());
}

void GamesWindow::drawLife()
{
    for(std::vector<sf::Sprite>::iterator it = m_Heart.getListHeart().begin(); it != m_Heart.getListHeart().end(); it ++)
    {
        drawElement(*it);
    }
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