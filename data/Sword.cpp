#include "Sword.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

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
        void Sword::animateAttack()
        {
            m_AnimationFram ++;
            setOrientation();
            setPosition();
            if(m_AnimationFram == 15)
            {
                endAnimation();
            }
        }
        void Sword::startAnimation(sf::Vector2f positionsword,int playerorientation, bool playerup, bool playerdown, bool playerright, bool playerleft)
        {
            //std::cout << "start attack" << std::endl;
            m_AnimationFram = 0;
            m_AniamtionExe = true;
            m_Rotate = playerorientation/* + 45*/;
            m_VectorAniamtor.x = positionsword.x + 2;
            m_VectorAniamtor.y = positionsword.y + 2;
            m_animationdown = playerdown;
            m_animationleft = playerleft;
            m_animationright = playerright;
            m_animationup = playerup;
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
            m_Rotate -= 6;
            m_Sprite.setRotation(m_Rotate);
        }
        void Sword::setPosition()
        {
            m_Sprite.setPosition(m_VectorAniamtor);
            if(m_animationdown)
            {
                m_VectorAniamtor.x += 4;
            }
            else if(m_animationleft)
            {
                m_VectorAniamtor.y += 4;
            }
            else if(m_animationright)
            {
                m_VectorAniamtor.y -= 4;
            }
            else if(m_animationup)
            {
                m_VectorAniamtor.x -= 4;
            }
        }
        void Sword::endAnimation()
        {
            m_AniamtionExe = false;
            m_animationdown = false;
            m_animationleft = false;
            m_animationright = false;
            m_animationup = false;
        }