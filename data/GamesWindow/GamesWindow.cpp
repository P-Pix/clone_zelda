/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "GamesWindow.hpp"

// Constructor / Destructor

    // Constructor
        GamesWindow::GamesWindow(): m_Bloc(m_blocname), m_Cavern(m_cavernname)
        {
            // Window size : (17* 64) * ((10 * 64) + 64) = 1088 * 704
            this -> m_Window = nullptr;
            this -> m_Window = new sf::RenderWindow(sf::VideoMode(m_windowwidth, m_windowheight), "Zelda Like");
            setMapUpdate();
            modifiHeart();
            //std::cout << "window create " << this << std::endl;
        }

    // Destructor
        GamesWindow::~GamesWindow()
        {
            //std::cout << "window delete " << this << std::endl;
        }