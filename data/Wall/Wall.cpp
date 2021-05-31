/**
 * @file Wall.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Wall.hpp"

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