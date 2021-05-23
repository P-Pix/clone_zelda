/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__MONSTER__)
#define __MONSTER__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
//#include "Ai.hpp"

class Monster
{
    public:
        // Constructeur / Destructeur
            // Constructeur
                Monster();
                Monster(const char *name);
            
            // Destructeur
                ~Monster();
                
        // Accessor
            // Sprite
                sf::Sprite getSprite();

            // Position
                sf::Vector2f getPosition();
                sf::Vector2f getNextPosition();

            // Power
                int getPower();

            // alive
                bool isAlive();     

        // Function
            // Attribution
                void setPower(int power);
                void moove();
                void nextPosition();
                void setDamage(int power);

                void recoilUp();
                void recoilDown();
                void recoilRight();
                void recoilLeft();

                void createPaternRelative(sf::Vector2f target);
    
    private:
        // Variable
            // basic
                int m_moveaction = 0,
                    m_power = 4,

                    m_life = 10;

                bool    m_alive = true,
                        m_turnxy = true;
                
                const char *m_monster = "skin/monster1.png";

            // std
                std::vector<sf::Vector2f> m_Patern;

            // SFML
                sf::Sprite  m_Sprite;
                sf::Texture m_Texture;

        // Function
            void createPaternStatic();
            void loadTexture(const char *name);
            void loadSprite();
            void initSprite();
            void loadPosition();

};

#endif