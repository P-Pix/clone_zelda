/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Wall.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

// Constructor / Destructor

    Wall::Wall()
    {
        this -> m_SWall = loadSprite();
        //std::cout << "wall create " << this << std::endl;
    }

    Wall::Wall(const char *nametxt)
    {
        this -> m_nametexture = nametxt;
        this -> m_SWall = loadSprite();
        //std::cout << "wall create " << this << std::endl;
    }

    Wall::~Wall()
    {
        //std::cout << "Wall delete " << this << std::endl;
    }