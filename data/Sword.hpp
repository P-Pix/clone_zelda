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
            int getPower();
            bool getExecution();

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
                
                const char *m_picture = "skin/sword2.png";

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
                void endAnimation();
};

#endif