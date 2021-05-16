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
        void GamesWindow::verificationWindow()
        {
            switchMap();
            canMove();
            swordAttack();
            collideMonster();
            if(!m_Player.isAlive())
            {
                this -> m_Window -> close();
            }
        }
        void GamesWindow::controlWindow()
        {
            this -> pollEvent();
        }

// Function private

    // collide : GamesWindowCollide.cpp

    // Map : GamesWindowMap.cpp

    // Drawing : GamesWindowDraw.cpp

    // Control : GamesWindowControl.cpp

    // modification
        void GamesWindow::modifiHeart()
        {
            this -> m_Heart.updateHeart(m_Player.getLife(), m_Player.getMaxLife());
        }
        void GamesWindow::modifMonster()
        {
            m_Mob1.moove();
        }
        void GamesWindow::makeListMonster()
        {
            m_listmob.clear();

            m_listmob.push_back(m_Mob1);
        }