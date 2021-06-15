/**
 * @file Wall.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__WALL__)
#define __WALL__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Wall
{
    public:
        // Constructor / Destructor
            Wall(void);
            Wall(const char *nametexture);

            ~Wall(void);

        // Accessor 
            sf::Sprite getSprite(void);
            std::vector<sf::Sprite> getListSprite(void);

        // Function
            void setPosition(sf::Vector2f position);
            void setPositionVector(std::vector<sf::Vector2f> vector);

    private:
        // Variable
            // basic
                const char  *m_nametexture = "skin/tree.png";

            // std
                std::vector<sf::Sprite> m_ListeSprite;

            // SFML/Graphics
                sf::Texture m_TWall;
                sf::Sprite  m_SWall;
        
        // Function
            sf::Sprite getSpritePosition(sf::Vector2f position);
            sf::Sprite loadSprite(void);
            void loadTexture(void);
};

#endif