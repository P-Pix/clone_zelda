#include "Sword.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor / Destructor

    // Constructor
        Sword::Sword()
        {
            std::cout << "Sword create" << std::endl;
            loadTexture();
            loadSprite();
        }   
    
    // Destructor
        Sword::~Sword()
        {
            std::cout << "Sword delete" << std::endl;
        }

// Accessor

    // Sprite
        sf::Sprite Sword::getSprite()
        {
            return m_Sprite;
        }
    
    // Power
        int Sword::getPower()
        {
            return m_Power;
        }
    
    // Execution
        bool Sword::getExecution()
        {
            return m_AniamtionExe;
        }

// Function public

    // Power
        void Sword::setPowerSword(int power)
        {
            m_Power = power;
        }

    // Animate
        void Sword::animateAttack(sf::Vector2f positionplayer)
        {
            m_AnimationFram ++;
            if(m_AnimationFram == 90)
            {
                endAnimation();
            }
        }
        void Sword::startAnimation()
        {
            std::cout << "start attack" << std::endl;
            m_AnimationFram = 0;
            m_AniamtionExe = true;
            m_Rotate = -45;
            /*
            m_PositionX =
            m_PositionY =
            m_AnimationFram = 0;
            */
        }

// Function private

    // Load Sword Representation
        void Sword::loadTexture()
        {
            if(!m_Texture.loadFromFile(m_Picture))
            {
                std::cout << "error load " << m_Picture << std::endl;
            }
        }
        void Sword::loadSprite()
        {
            m_Sprite.setTexture(m_Texture);
        }
    
    // Animate Attack
        void Sword::setOrientation()
        {
            m_Rotate ++;
            m_Sprite.setRotation(m_Rotate);
        }
        void Sword::setPosition(sf::Vector2f positionplayer)
        {
            m_VectorAniamtor.x = positionplayer.x + m_PositionX;
            m_VectorAniamtor.y = positionplayer.y + m_PositionY;
            m_Sprite.setPosition(m_VectorAniamtor);
        }
        void Sword::endAnimation()
        {
            m_AniamtionExe = false;
        }