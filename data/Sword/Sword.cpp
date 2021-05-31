/**
 * @file Sword.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Sword.hpp"

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