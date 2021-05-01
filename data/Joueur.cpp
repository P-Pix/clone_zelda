#include "Joueur.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// Constructor / Destructor

    // Constructor
        Joueur::Joueur(): m_Spown(sf::Vector2f(10 * 64.f, 7 * 64.f))
        {
            this -> m_Shero = loadSprite(m_NCF1, m_Spown);
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
            return m_OrientationDown;
        }
        bool Joueur::getOrientationLeft()
        {
            return m_OrientationLeft;
        }
        bool Joueur::getOrientationRight()
        {
            return m_OrientationRight;
        }
        bool Joueur::getOrientationUp()
        {
            return m_OrientationUp;
        }
        int Joueur::getOrientationValue()
        {
            if(m_OrientationDown)
            {
                return 90;
            }
            else if(m_OrientationLeft)
            {
                return 180;
            }
            else if(m_OrientationRight)
            {
                return 0;
            }
            else if(m_OrientationUp)
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
            return m_Life;
        }
        int Joueur::getMaxLife()
        {
            return m_MaxLife;
        }

    // Position
        sf::Vector2f Joueur::getPosition()
        {
            return m_Shero.getPosition();
        }
        sf::Vector2f Joueur::getPositionSword()
        {
            sf::Vector2f positionsword(0.f, 0.f);
            if(m_OrientationDown)
            {
                positionsword.x = m_Shero.getPosition().x;
                positionsword.y = m_Shero.getPosition().y + 64;
                return positionsword;
            }
            else if(m_OrientationLeft)
            {
                positionsword.x = m_Shero.getPosition().x;
                positionsword.y = m_Shero.getPosition().y;
                return positionsword;
            }
            else if(m_OrientationRight)
            {
                positionsword.x = m_Shero.getPosition().x + 64;
                positionsword.y = m_Shero.getPosition().y + 64;
                return positionsword;
            }
            else if(m_OrientationUp)
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
            m_MaxLife += 4;
            m_Life = m_MaxLife;
        }
        void Joueur::setHeart()
        {
            m_Life += 4;
            if(m_Life > m_MaxLife)
            {
                m_Life = m_MaxLife;
            }
        }
        void Joueur::setDamage(int power)
        {
            m_Life -= power;
        }

    // Animation 
        void Joueur::animationMoveRight()
        {
            if(m_MoveRight % 4 == 0)
            {
                loadTexture(m_NCF1);
            }
            else if(m_MoveRight % 4 == 1)
            {
                loadTexture(m_NCF2);
            }
            else if(m_MoveRight % 4 == 2)
            {
                loadTexture(m_NCF3);
            }
            else
            {
                loadTexture(m_NCF4);
            }
            m_MoveRight ++;
            this -> m_Shero.move(sf::Vector2f(m_Vitesse * 1.f, 0.f));
        }
        void Joueur::animationMoveLeft()
        {
            if(m_MoveLeft % 4 == 0)
            {
                loadTexture(m_NCF1);
            }
            else if(m_MoveLeft % 4 == 1)
            {
                loadTexture(m_NCF2);
            }
            else if(m_MoveLeft % 4 == 2)
            {
                loadTexture(m_NCF3);
            }
            else
            {
                loadTexture(m_NCF4);
            }
            m_MoveLeft ++;
            this -> m_Shero.move(sf::Vector2f(m_Vitesse * -1.f, 0.f));
        }
        void Joueur::animationMoveUp()
        {
            if(m_MoveUp % 4 == 0)
            {
                loadTexture(m_NCF1);
            }
            else if(m_MoveUp % 4 == 1)
            {
                loadTexture(m_NCF2);
            }
            else if(m_MoveUp % 4 == 2)
            {
                loadTexture(m_NCF3);
            }
            else
            {
                loadTexture(m_NCF4);
            }
            m_MoveUp ++;
            this -> m_Shero.move(sf::Vector2f(0.f, m_Vitesse * -1.f));
        }
        void Joueur::animationMoveDown()
        {
            if(m_MoveDown % 8 == 0)
            {
                loadTexture(m_NCF0);
                m_MoveDown = 0;
            }
            else if(m_MoveDown % 8 == 1)
            {
                loadTexture(m_NCF1);
            }
            else if(m_MoveDown % 8 == 2)
            {
                loadTexture(m_NCF2);
            }
            else if(m_MoveDown % 8 == 3)
            {
                loadTexture(m_NCF3);
            }
            else if(m_MoveDown % 8 == 4)
            {
                loadTexture(m_NCF4);
            }
            else if(m_MoveDown % 8 == 5)
            {
                loadTexture(m_NCF5);
            }
            else if(m_MoveDown % 8 == 6)
            {
                loadTexture(m_NCF6);
            }
            else
            {
                loadTexture(m_NCF7);
            }
            m_MoveDown ++;
            this -> m_Shero.move(sf::Vector2f(0.f, m_Vitesse * 1.f));
        }

    // Switch Orientation
        void Joueur::setOrientationDown()
        {
            //std::cout << "Switch orientation D" << std::endl;
            m_OrientationDown = true;
            m_OrientationLeft = false;
            m_OrientationRight = false;
            m_OrientationUp = false;
        }
        void Joueur::setOrientationLeft()
        {
            //std::cout << "Switch orientation L" << std::endl;
            m_OrientationDown = false;
            m_OrientationLeft = true;
            m_OrientationRight = false;
            m_OrientationUp = false;            
        }
        void Joueur::setOrientationUp()
        {
            //std::cout << "Switch orientation U" << std::endl;
            m_OrientationDown = false;
            m_OrientationLeft = false;
            m_OrientationRight = false;
            m_OrientationUp = true;            
        }
        void Joueur::setOrientationRight()
        {
            //std::cout << "Switch orientation R" << std::endl;
            m_OrientationDown = false;
            m_OrientationLeft = false;
            m_OrientationRight = true;
            m_OrientationUp = false;            
        }

// Fonction Private

    // Sprite Generator
        sf::Sprite Joueur::loadSprite(const char *NAME, sf::Vector2f VECTOR)
        {
            sf::Sprite SPRITE;
            loadTexture(NAME);
            SPRITE.setTexture(m_Thero);
            SPRITE.setPosition(VECTOR);
            SPRITE.setScale(2, 2);
            return SPRITE;
        }
        void Joueur::loadTexture(const char *NAME)
        {
            if(!m_Thero.loadFromFile(NAME))
            {
                std::cout << "error image " << NAME << std::endl;
            }
        }