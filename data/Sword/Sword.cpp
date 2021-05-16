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
            return m_power;
        }
    
    // Execution
        bool Sword::getExecution()
        {
            return m_aniamtionexe;
        }
        bool Sword::getAttackUp()
        {
            return m_animationup;
        }
        bool Sword::getAttackLeft()
        {
            return m_animationleft;
        }
        bool Sword::getAttackRight()
        {
            return m_animationright;
        }
        bool Sword::getAttackDown()
        {
            return m_animationdown;
        }

// Function public

    // Power
        void Sword::setPowerSword(int power)
        {
            m_power = power;
        }

    // Animate
        void Sword::animateAttack()
        {
            m_animationfram ++;
            /*
            setOrientation();
            setPosition();
            */
            if(m_animationfram == 15)
            {
                endAnimation();
            }
        }
        void Sword::startAnimation(sf::Vector2f positionsword,int playerorientation)
        {
            //std::cout << "start attack" << std::endl;
            m_animationfram = 0;
            m_aniamtionexe = true;
            m_rotate = playerorientation /*- 45*/;
            m_Sprite.setRotation(m_rotate);
            m_VectorAniamtor.x = positionsword.x/*+ 2*/;
            m_VectorAniamtor.y = positionsword.y/*+ 2*/;
            setBasicPosition();
        }
    
    // Orientation
        void Sword::setOrientationDown(bool playerdown)
        {
            m_animationdown = playerdown;
        }
        void Sword::setOrientationLeft(bool playerleft)
        {
            m_animationleft = playerleft;
        }
        void Sword::setOrientationRight(bool playerright)
        {
            m_animationright = playerright;
        }
        void Sword::setOrientationUp(bool playerup)
        {
            m_animationup = playerup;
        }

// Function private

    // Load Sword Representation
        void Sword::loadTexture()
        {
            if(!m_Texture.loadFromFile(m_picture))
            {
                std::cout << "error load " << m_picture << std::endl;
            }
        }
        void Sword::loadSprite()
        {
            m_Sprite.setTexture(m_Texture);
        }
    
    // Animate Attack
        void Sword::setOrientation()
        {
            m_rotate -= 6;
            m_Sprite.setRotation(m_rotate);
        }
        void Sword::setBasicPosition()
        {
            if(m_animationdown)
            {
                m_VectorAniamtor.x += 64;
                m_VectorAniamtor.y += 0 ;
            }
            else if(m_animationleft)
            {
                m_VectorAniamtor.x += 0;
                m_VectorAniamtor.y += 64;
            }
            else if(m_animationright)
            {
                m_VectorAniamtor.x += 0;
                m_VectorAniamtor.y -= 64;
            }
            else if(m_animationup)
            {
                m_VectorAniamtor.x -= 64;
                m_VectorAniamtor.y += 0;
            }
            m_Sprite.setPosition(m_VectorAniamtor);
        }
        void Sword::setPosition()
        {
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
            m_Sprite.setPosition(m_VectorAniamtor);
        }
        void Sword::endAnimation()
        {
            m_aniamtionexe = false;
            m_animationdown = false;
            m_animationleft = false;
            m_animationright = false;
            m_animationup = false;
        }