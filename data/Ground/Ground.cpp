/**
 * @file Ground.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Ground.hpp"

// Constructor / Destructor

    // Constructor
        Ground::Ground(void)
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
        Ground::~Ground(void)
        {
            //std::cout << "Ground deete " << this << std::endl;
        }