/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#include "Joueur.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

    // Constructor
        Joueur::Joueur(): m_Spown(sf::Vector2f(10 * 64.f, 7 * 64.f))
        {
            this -> m_Shero = loadSprite(m_ncf0, m_Spown);
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
    
    // About Life
        int Joueur::getLife()
        {
            return m_life;
        }
        int Joueur::getMaxLife()
        {
            return m_maxlife;
        }
        bool Joueur::isAlive()
        {
            return m_alive;
        }

    // Position : JoueurAccessorPosition.cpp

// Function public

    // Replace player when it's a new map : JoueurPublicMove.cpp

    // Function about life
        void Joueur::setMaxLifeUp()
        {
            m_maxlife += 4;
            m_life = m_maxlife;
        }
        void Joueur::setHeart()
        {
            m_life += 4;
            if(m_life > m_maxlife)
            {
                m_life = m_maxlife;
            }
        }
        void Joueur::setDamage(int power)
        {
            // creer les fram d'invulnérabilité
            m_life -= power;
            if(m_life <= 0)
            {
                m_life = 0;
                m_alive = false;
            }
        }

    // Animation : JoueurPublicAnimation.cpp

    // recoil : JoueurPublicMove.cpp

    // Switch Orientation : JoueurPublicSwitchOrientation.cpp

// Fonction Private

    // Sprite Generator : JoueurPrivateSprite.cpp