/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Sword.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor / Destructor

    // Constructor
        Sword::Sword()
        {
            //std::cout << "Sword create" << std::endl;
            loadTexture();
            loadSprite();
        }   
    
    // Destructor
        Sword::~Sword()
        {
            //std::cout << "Sword delete" << std::endl;
        }