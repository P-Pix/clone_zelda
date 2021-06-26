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

#ifndef _SWORD_HPP_
#define _SWORD_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
class Sword
{
    public:
        // Constructor / Destructor
            // Constructor
                Sword(void);

            // Destructor
                ~Sword(void);

        // Accessor
            sf::Sprite getSprite(void);
            sf::Vector2f getPosition(void);
            
            int getPower(void);
            bool getExecution(void);

            bool getAttackUp(void);
            bool getAttackLeft(void);
            bool getAttackRight(void);
            bool getAttackDown(void);

        // Function
            void setPowerSword(int power);
            void animateAttack(void);
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
                
                const char *m_picture = "image/sword.png";

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
                void loadTexture(void);
                void loadSprite(void);

            //Animate Attack
                void setOrientation(void);
                void setPosition(void);
                void setBasicPosition(void);
                void endAnimation(void);
};

#endif