/**
 * @file Monster.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Monster.hpp"

// Constructor / Desttructor
    // Constructor
        Monster::Monster()
        {
            //std::cout << "Monster create " << this << std::endl;
            initSprite();
            std::srand(std::time(nullptr));
            createPaternRelative();
        }
        Monster::Monster(const char *name)
        {
            m_monster = name;
            initSprite();
            std::srand(std::time(nullptr));
            createPaternRelative();
        }

    // Destructeur
        Monster::~Monster()
        {
            //std::cout << "Monster delete " << this << std::endl;
        }