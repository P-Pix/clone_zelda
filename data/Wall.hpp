#if !defined(__WALL__)
#define __WALL__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Wall
{
    public:
        // Constructor / Destructor
            Wall();
            Wall(const char *nametexture);

            ~Wall();

        // Accessor 
            sf::Sprite getSprite();
            std::vector<sf::Sprite> getListSprite();

        // Function
            void setPosition(sf::Vector2f POSITION);
            void setPositionVector(std::vector<sf::Vector2f> vector);

    private:
        // Variable
            // iostream
                const char  *m_NameTexture = "skin/tree.png";
                std::vector<sf::Sprite> m_ListeSprite;

            // SFML/Graphics
                sf::Texture m_TWall;
                sf::Sprite  m_SWall;
        
        // Function
            sf::Sprite getSpritePosition(sf::Vector2f position);
            sf::Sprite loadSprite();
            void loadTexture();
};

#endif