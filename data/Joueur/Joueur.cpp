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

    // Orientation
        bool Joueur::getOrientationDown()
        {
            return m_orientationdown;
        }
        bool Joueur::getOrientationLeft()
        {
            return m_orientationleft;
        }
        bool Joueur::getOrientationRight()
        {
            return m_orientationright;
        }
        bool Joueur::getOrientationUp()
        {
            return m_orientationup;
        }
        int Joueur::getOrientationValue()
        {
            if(m_orientationdown)
            {
                return 90;
            }
            else if(m_orientationleft)
            {
                return 180;
            }
            else if(m_orientationright)
            {
                return 0;
            }
            else if(m_orientationup)
            {
                return 270;
            }
            return 0;
        }

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

    // Position
        sf::Vector2f Joueur::getPosition()
        {
            return m_Shero.getPosition();
        }
        sf::Vector2f Joueur::getPositionSword()
        {
            sf::Vector2f positionsword(0.f, 0.f);
            if(m_orientationdown)
            {
                positionsword.x = m_Shero.getPosition().x;
                positionsword.y = m_Shero.getPosition().y + 64;
                return positionsword;
            }
            else if(m_orientationleft)
            {
                positionsword.x = m_Shero.getPosition().x;
                positionsword.y = m_Shero.getPosition().y;
                return positionsword;
            }
            else if(m_orientationright)
            {
                positionsword.x = m_Shero.getPosition().x + 64;
                positionsword.y = m_Shero.getPosition().y + 64;
                return positionsword;
            }
            else if(m_orientationup)
            {
                positionsword.x = m_Shero.getPosition().x + 64;
                positionsword.y = m_Shero.getPosition().y;
                return positionsword;
            }
            return m_Shero.getPosition();
        }

// Function public

    // Replace player when it's a new map
        void Joueur::setPositionDown()
        {
            float   x = m_Shero.getPosition().x,
                    y = m_Shero.getPosition().y - 640;
            m_Shero.setPosition(sf::Vector2f(x, y));
        }
        void Joueur::setPositionUp()
        {
            float   x = m_Shero.getPosition().x,
                    y = m_Shero.getPosition().y + 640;
            m_Shero.setPosition(sf::Vector2f(x, y));
        }
        void Joueur::setPositionRight()
        {
            float   x = m_Shero.getPosition().x - 1088,
                    y = m_Shero.getPosition().y;
            m_Shero.setPosition(sf::Vector2f(x, y));
        }
        void Joueur::setPositionLeft()
        {
            float   x = m_Shero.getPosition().x + 1088,
                    y = m_Shero.getPosition().y;
            m_Shero.setPosition(sf::Vector2f(x, y));
        }

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

    // Animation 
        void Joueur::animationMoveRight()
        {
            if(m_moveright % 4 == 0)
            {
                loadTexture(m_ncf1);
            }
            else if(m_moveright % 4 == 1)
            {
                loadTexture(m_ncf2);
            }
            else if(m_moveright % 4 == 2)
            {
                loadTexture(m_ncf3);
            }
            else
            {
                loadTexture(m_ncf4);
            }
            m_moveright ++;
            this -> m_Shero.move(sf::Vector2f(m_vitesse * 1.f, 0.f));
        }
        void Joueur::animationMoveLeft()
        {
            if(m_moveleft % 4 == 0)
            {
                loadTexture(m_ncf1);
            }
            else if(m_moveleft % 4 == 1)
            {
                loadTexture(m_ncf2);
            }
            else if(m_moveleft % 4 == 2)
            {
                loadTexture(m_ncf3);
            }
            else
            {
                loadTexture(m_ncf4);
            }
            m_moveleft ++;
            this -> m_Shero.move(sf::Vector2f(m_vitesse * -1.f, 0.f));
        }
        void Joueur::animationMoveUp()
        {
            if(m_moveup % 4 == 0)
            {
                loadTexture(m_ncf1);
            }
            else if(m_moveup % 4 == 1)
            {
                loadTexture(m_ncf2);
            }
            else if(m_moveup % 4 == 2)
            {
                loadTexture(m_ncf3);
            }
            else
            {
                loadTexture(m_ncf4);
            }
            m_moveup ++;
            this -> m_Shero.move(sf::Vector2f(0.f, m_vitesse * -1.f));
        }
        void Joueur::animationMoveDown()
        {
            if(m_movedown % 8 == 0)
            {
                loadTexture(m_ncf0);
                m_movedown = 0;
            }
            else if(m_movedown % 8 == 1)
            {
                loadTexture(m_ncf1);
            }
            else if(m_movedown % 8 == 2)
            {
                loadTexture(m_ncf2);
            }
            else if(m_movedown % 8 == 3)
            {
                loadTexture(m_ncf3);
            }
            else if(m_movedown % 8 == 4)
            {
                loadTexture(m_ncf4);
            }
            else if(m_movedown % 8 == 5)
            {
                loadTexture(m_ncf5);
            }
            else if(m_movedown % 8 == 6)
            {
                loadTexture(m_ncf6);
            }
            else
            {
                loadTexture(m_ncf7);
            }
            m_movedown ++;
            this -> m_Shero.move(sf::Vector2f(0.f, m_vitesse * 1.f));
        }

    // recoil
        void Joueur::recoilDown()
        {
            m_Shero.move(sf::Vector2f(0.f, 64.f));
        }
        void Joueur::recoilLeft()
        {
            m_Shero.move(sf::Vector2f(-64.f, 0.f));
        }
        void Joueur::recoilRight()
        {
            m_Shero.move(sf::Vector2f(6.f, 0.f));
        }
        void Joueur::recoilUp()
        {
            m_Shero.move(sf::Vector2f(0.f, -64.f));
        }

    // Switch Orientation
        void Joueur::setOrientationDown()
        {
            //std::cout << "Switch orientation D" << std::endl;
            m_orientationdown = true;
            m_orientationleft = false;
            m_orientationright = false;
            m_orientationup = false;
        }
        void Joueur::setOrientationLeft()
        {
            //std::cout << "Switch orientation L" << std::endl;
            m_orientationdown = false;
            m_orientationleft = true;
            m_orientationright = false;
            m_orientationup = false;            
        }
        void Joueur::setOrientationUp()
        {
            //std::cout << "Switch orientation U" << std::endl;
            m_orientationdown = false;
            m_orientationleft = false;
            m_orientationright = false;
            m_orientationup = true;            
        }
        void Joueur::setOrientationRight()
        {
            //std::cout << "Switch orientation R" << std::endl;
            m_orientationdown = false;
            m_orientationleft = false;
            m_orientationright = true;
            m_orientationup = false;            
        }

// Fonction Private

    // Sprite Generator
        sf::Sprite Joueur::loadSprite(const char *name, sf::Vector2f vector)
        {
            sf::Sprite sprite;
            loadTexture(name);
            sprite.setTexture(m_Thero);
            sprite.setPosition(vector);
            sprite.setScale(2, 2);
            return sprite;
        }
        void Joueur::loadTexture(const char *name)
        {
            if(!m_Thero.loadFromFile(name))
            {
                std::cout << "error image " << name << std::endl;
            }
        }