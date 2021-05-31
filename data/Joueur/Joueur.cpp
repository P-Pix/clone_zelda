/**
 * @file Joueur.cpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Joueur.hpp"

// Constructor / Destructor

    // Constructor
        Joueur::Joueur(): m_Spown(sf::Vector2f(10 * 64.f, 7 * 64.f))
        {
            this -> m_Shero = loadSprite(m_ncf0, m_Spown);
            makeListeAnimation();
            m_Heart.updateHeart(m_life, m_maxlife);
            //std::cout << "player create " << this << std::endl;
        }

    // Destructor
        Joueur::~Joueur()
        {
            //std::cout << "player delete " << this << std::endl;
        }

// Accessor

    // Orientation : JoueurAccessorOrientation.cpp

    // Sprite
        sf::Sprite Joueur::getSprite()
        {
            return m_Shero;
        }

    // Adress
        Joueur *Joueur::getAdress()
        {
            return this;
        }