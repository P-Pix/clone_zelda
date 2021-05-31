/**
 * @file Sword.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__SWORD__)
#define __SWORD__

#include <iostream>
#include <SFML/Graphics.hpp>
class Sword
{
    public:
        // Constructor / Destructor
            // Constructor
                Sword();

            // Destructor
                ~Sword();

        // Accessor
            sf::Sprite getSprite();
            sf::Vector2f getPosition();
            
            int getPower();
            bool getExecution();

            bool getAttackUp();
            bool getAttackLeft();
            bool getAttackRight();
            bool getAttackDown();

        // Function
            void setPowerSword(int power);
            void animateAttack();
            void startAnimation(sf::Vector2f positionsword, int playerorientation);

            void setOrientationUp(bool playerup);
            void setOrientationDown(bool playerdown);
            void setOrientationLeft(bool playerleft);
            void setOrientationRight(bool playerright);

    private:
        // Variable
            // basic
                int m_power = 4,
                    m_animationfram = 0,
                    m_rotate = 0; // start animation right -45° to 45°
                
                const char *m_picture = "skin/sword.png";

                bool    m_aniamtionexe = false,

                        m_animationdown = false,
                        m_animationup = false,
                        m_animationright = false,
                        m_animationleft = false;

            // SFML
                sf::Texture m_Texture;
                sf::Sprite m_Sprite;
                sf::Vector2f m_VectorAniamtor; // start animation right-bottom player sprite to right-top

        // Function
            // Load sword
                void loadTexture();
                void loadSprite();

            //Animate Attack
                void setOrientation();
                void setPosition();
                void setBasicPosition();
                void endAnimation();
};

#endif