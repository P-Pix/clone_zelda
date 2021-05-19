/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Ground.hpp"

// Constructor / Destructor

    // Constructor
        Ground::Ground()
        {
            initSprite();
            //std::cout << "Ground create " << this << std::endl;
        }
        Ground::Ground(const char *name)
        {
            this -> m_name = name;
            initSprite();
            //std::cout << "Ground create " << name << " " << this << std::endl;
        }

    // Destructor
        Ground::~Ground()
        {
            //std::cout << "Ground deete " << this << std::endl;
        }