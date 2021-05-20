/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Monster.hpp"
#include <iostream>

// Constructor / Desttructor
    // Constructor
        Monster::Monster()
        {
            //std::cout << "Monster create " << this << std::endl;
            createPatern();
            initSprite();
        }

    // Destructeur
        Monster::~Monster()
        {
            //std::cout << "Monster delete " << this << std::endl;
        }