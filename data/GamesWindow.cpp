#include <iostream>
#include <SFML/Graphics.hpp>
#include "GamesWindow.hpp"
#include <vector>

// Constructor / Destructor

    // Constructor
        GamesWindow::GamesWindow(): m_Bloc(m_blocname), m_Cavern(m_cavernname)
        {
            this -> m_Window = nullptr;
            //(17* 64) * ((10 * 64) + 64) = 1088 * 704
            this -> m_Window = new sf::RenderWindow(sf::VideoMode(m_windowwidth, m_windowheight), "Zelda Like");
            //std::cout << "window create " << this << std::endl;
            setMapUpdate();
            modifiHeart();
        }

    // Destructor
        GamesWindow::~GamesWindow()
        {
            //std::cout << "window delete " << this << std::endl;
        }

// Accessor

    // Window Open
        bool GamesWindow::isRunning()
        {
            return m_Window -> isOpen();
        }

// Function public

    // Controls options
        void GamesWindow::limitFramerate(int frame)
        {
            this -> m_Window -> setFramerateLimit(frame);
        }

    // Always call in the main
        void GamesWindow::updateWindow()
        {
            this -> m_Window -> clear();
            modifMonster();
            allDrawWindow();
            this -> m_Window -> display();
        }
        void GamesWindow::tchecWindow()
        {
            switchMap();
            if(collide(m_Player.getSprite(), m_Mob1.getSprite()))
            {
                m_Player.setDamage(m_Mob1.getPower());
                m_Heart.updateHeart(m_Player.getLife(), m_Player.getMaxLife());
            }
        }
        void GamesWindow::controlWindow()
        {
            this -> pollEvent();
        }

// Function private

    // test
        bool GamesWindow::collide(sf::Sprite sprite1, sf::Sprite sprite2)
        {
            int sprite1x = sprite1.getPosition().x,
                sprite1y = sprite1.getPosition().y,

                sprite2x = sprite2.getPosition().x,
                sprite2y = sprite2.getPosition().y;

            if(sprite1x <= sprite2x + 64 && sprite1x + 64 >= sprite2x && sprite1y <= sprite2y + 64 && sprite1y + 64 > sprite2y)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

    // New Map
        void GamesWindow::setMapUpdate()
        {
            loadNewMap();
            setBackground();
        }
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

    // Drawing
        void GamesWindow::drawElement(sf::Sprite sprite)
        {
            this -> m_Window -> draw(sprite);
        }
        void GamesWindow::allDrawWindow()
        {
            drawVector(m_Heart.getListSprite());

            drawVector(m_Bloc.getListSprite());
            drawVector(m_Cavern.getListSprite());
            drawVector(m_Tree.getListSprite());
            drawVector(m_Ground.getListSprite());

            drawElement(m_Mob1.getSprite());
            drawElement(m_Player.getSprite());
            drawSword();
        }
        void GamesWindow::drawVector(std::vector<sf::Sprite> vector)
        {
            for(int number = 0;  number < vector.size(); number ++)
            {
                drawElement(vector[number]);
            }
        }
        void GamesWindow::drawSword()
        {
            if(m_Sword.getExecution())
            {
                m_Sword.animateAttack();
                drawElement(m_Sword.getSprite());
            }
        }

    // Controls
        void GamesWindow::pollEvent()
        {
            if(this -> m_Window -> pollEvent(this -> m_Event))
            {
                if(this -> m_Event.type == sf::Event::Closed)
                {
                    this -> m_Window -> close();
                }
                else if (this -> m_Event.type == sf::Event::KeyPressed)
                {
                    if(this -> m_Event.key.code == sf::Keyboard::Escape)
                    {
                        this -> m_Window -> close();
                    }
                    else if(this -> m_Event.key.code == sf::Keyboard::Down)
                    {
                        if(!m_Sword.getExecution())
                        {
                            if(!m_Player.getOrientationDown())
                            {
                                m_Player.setOrientationDown();
                            }
                            m_Player.animationMoveDown();
                        }
                    }
                    else if(this -> m_Event.key.code == sf::Keyboard::Up)
                    {
                        if(!m_Sword.getExecution())
                        {
                            if(!m_Player.getOrientationUp())
                            {
                                m_Player.setOrientationUp();
                            }
                            m_Player.animationMoveUp();
                        }
                    }
                    else if(this -> m_Event.key.code == sf::Keyboard::Left)
                    {
                        if(!m_Sword.getExecution())
                        {
                            if(!m_Player.getOrientationLeft())
                            {
                                m_Player.setOrientationLeft();
                            }
                            m_Player.animationMoveLeft();
                        }
                    }
                    else if(this -> m_Event.key.code == sf::Keyboard::Right)
                    {
                        if(!m_Sword.getExecution())
                        {
                            if(!m_Player.getOrientationRight())
                            {
                                m_Player.setOrientationRight();
                            }
                            m_Player.animationMoveRight();
                        }
                    }
                    else if(this -> m_Event.key.code == sf::Keyboard::Space)
                    {
                        if(!m_Sword.getExecution())
                        {
                            m_Sword.setOrientationUp(m_Player.getOrientationUp()); 
                            m_Sword.setOrientationDown(m_Player.getOrientationDown());
                            m_Sword.setOrientationRight(m_Player.getOrientationRight());
                            m_Sword.setOrientationLeft(m_Player.getOrientationLeft());
                            m_Sword.startAnimation(m_Player.getPositionSword(), m_Player.getOrientationValue());
                        }
                    }
                }
            }
        }

    // Life
        void GamesWindow::modifiHeart()
        {
            this -> m_Heart.updateHeart(m_Player.getLife(), m_Player.getMaxLife());
        }
    
    // Monster
    void GamesWindow::modifMonster()
    {
        m_Mob1.moove();
    }