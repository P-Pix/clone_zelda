#if !defined(__WALL__)
#define __WALL__

#include <iostream>
#include <SFML/Graphics.hpp>

class Wall
{
    public:
        // Constructor / Destructor
            Wall();
            Wall(const char *nametexture);

            ~Wall();

        // Accessor 
            sf::Sprite getSprite();

        // Function
            void setPosition(sf::Vector2f POSITION);

    private:
        // Variable
            // iostream
                const char *m_NameTexture = "skin/tree.png";

            // SFML/Graphics
                sf::Texture m_TWall;
                sf::Sprite m_SWall;
        
        // Function
            sf::Sprite loadSprite();
            void loadTexture();
};

#endif