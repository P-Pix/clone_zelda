#if !defined(__MONSTER__)
#define __MONSTER__

#include <SFML/Graphics.hpp>
#include <iostream>

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
    
    private:
        // Variable
            // basic

            // std

            // SFML
                sf::Sprite  m_Sprite;
                sf::Texture m_Texture;

};

#endif