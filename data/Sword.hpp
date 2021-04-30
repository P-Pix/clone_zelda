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
            void animateAttack(sf::Vector2f positionplayer);
            void startAnimation();

    private:
        // Variable
            // iostream
                int m_Power = 4,
                    m_AnimationFram = 0,
                    m_Rotate = 0, // start animation right -45° to 45°
                    m_PositionX = 0,
                    m_PositionY = 0;
                
                const char *m_Picture = "skin/sword.png";

                bool m_AniamtionExe = false;

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
                void setPosition(sf::Vector2f positionplayer);
                void endAnimation();
};

#endif