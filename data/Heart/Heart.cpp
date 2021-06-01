/**
 * @file Heart.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Heart.hpp"

// Consructor / Destructor

    // Constructor
        Heart::Heart()
        {
            initConstructor();
            //std::cout << "heart create " << this << std::endl;
        }
        Heart::Heart(int frameinvulnerable)
        {
            m_frameinvulnerable = frameinvulnerable;
            initConstructor();
        }

    // Destructor
        Heart::~Heart()
        {
            //std::cout << "heart delete " << this << std::endl;
        }