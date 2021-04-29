#include <iostream>
#include <SFML/Graphics.hpp>
#include "GamesWindow.hpp"
#include "Joueur.hpp"
#include "Heart.hpp"
#include <vector>

// Constructor / Destructor

GamesWindow::GamesWindow(): m_Bloc(m_bloc), m_Cavern(m_cavern)
{
    this -> m_Window = nullptr;
    //(17* 64) * ((10 * 64) + 64) = 1088 * 704
    this -> m_Window = new sf::RenderWindow(sf::VideoMode(1088, 704), "Zelda Like");
    //std::cout << "window create " << this << std::endl;
}

GamesWindow::~GamesWindow()
{
    //std::cout << "window delete " << this << std::endl;
}

// Accessor

bool GamesWindow::isRunning()
{
    return m_Window -> isOpen();
}

// Function public

void GamesWindow::setMapUpdate()
{
    loadNewMap();
    setBackground();
}

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

void GamesWindow::tchecWindow()
{
    switchMap();
}

void GamesWindow::controlWindow()
{
    this -> pollEvent();
}

void GamesWindow::setDrawing(sf::Sprite SPRITE)
{
    drawElement(SPRITE);
}

// Function private

void GamesWindow::switchMap()
{
    if(m_Player.getPosition().x < 0)
    {
        m_Map.setMapLeft();
        setMapUpdate();
        m_Player.setPositionLeft();
    }
    else if(m_Player.getPosition().x > 1088)
    {
        m_Map.setMapRight();
        setMapUpdate();
        m_Player.setPositionRight();
    }
    else if(m_Player.getPosition().y < 64)
    {
        m_Map.setMapUp();
        setMapUpdate();
        m_Player.setPositionUp();
    }
    if(m_Player.getPosition().y > 704)
    {
        m_Map.setMapDown();
        setMapUpdate();
        m_Player.setPositionDown();
    }
}

void GamesWindow::loadNewMap()
{
    m_Map.generateMap();
}

void GamesWindow::setBackground()
{
    m_Bloc.setPositionVector(m_Map.getListPositionWallInt());
    m_Cavern.setPositionVector(m_Map.getListPositionGroundInt());
    m_Tree.setPositionVector(m_Map.getListPositionWallExt());
    m_Ground.setPositionVector(m_Map.getListPositionGroundExt());
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
    m_Bloc.setPosition(sf::Vector2f(0.f, 192.f));
    m_Tree.setPosition(sf::Vector2f(0.f, 128.f));
    m_Ground.setPosition(sf::Vector2f(64.f, 64.f));
    m_Cavern.setPosition(sf::Vector2f(64.f, 128.f));
}

void GamesWindow::allDrawWindow()
{
    drawVector(m_Heart.getListHeart());

    drawVector(m_Bloc.getListSprite());
    drawVector(m_Cavern.getListSprite());
    drawVector(m_Tree.getListSprite());
    drawVector(m_Ground.getListSprite());

    drawElement(m_Player.getSprite());
}

void GamesWindow::drawVector(std::vector<sf::Sprite> vector)
{
    for(int number = 0;  number < vector.size(); number ++)
    {
        drawElement(vector[number]);
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