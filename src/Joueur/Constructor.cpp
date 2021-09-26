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

#include "../../include/Joueur.hpp"

// Constructor / Destructor

// Constructor
Joueur::Joueur(void) : m_Spown(sf::Vector2f(10 * 64.f, 7 * 64.f)) {
    this->m_Shero = loadSprite(m_ncf0, m_Spown);
    makeListeAnimation();
    m_Heart.updateHeart();
    //std::cout << "player create " << this << std::endl;
}

// Destructor
Joueur::~Joueur(void) {
    //std::cout << "player delete " << this << std::endl;
}

// Accessor

// Orientation : JoueurAccessorOrientation.cpp

// Sprite
sf::Sprite Joueur::getSprite(void) {
    return m_Shero;
}

// Adress
Joueur *Joueur::getAdress(void) {
    return this;
}