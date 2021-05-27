/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Monster.hpp"

// Constructor / Desttructor
    // Constructor
        Monster::Monster()
        {
            //std::cout << "Monster create " << this << std::endl;
            createPaternStatic();
            initSprite();
        }

    // Destructeur
        Monster::~Monster()
        {
            //std::cout << "Monster delete " << this << std::endl;
        }