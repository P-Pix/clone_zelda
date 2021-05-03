#if !defined(__MONSTER__)
#define __MONSTER__

#include <SFML/Graphics.hpp>
#include <iostream>
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

            // Power
                int getPower();

        // Function
            // Attribution
                void setPower(int power);
                void moove();
    
    private:
        // Variable
            // basic
                int m_moveaction = 0,
                    m_power = 4;
                
                const char *m_monster = "skin/monster1.png";

            // std
                std::vector<sf::Vector2f> m_Patern;

            // SFML
                sf::Sprite  m_Sprite;
                sf::Texture m_Texture;

        // Function
            void createPatern();
            void loadTexture(const char *name);
            void loadSprite();
            void initSprite();

};

#endif