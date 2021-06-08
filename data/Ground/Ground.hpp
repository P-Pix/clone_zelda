/**
 * @file Ground.hpp
 * @author Guillaume LEMONNIER
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(__GROUND__)
#define __GROUND__

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
class Ground
{
    public:
        // Constructor / Destrutor
            Ground(void);
            Ground(const char *name);
            ~Ground(void);
        
        // Accessor
            std::vector<sf::Sprite> getListSprite(void);
            sf::Sprite getSprite(void);
            Ground* getAdress(void);
        
        // Function
            void setPositionVector(std::vector<sf::Vector2f> vector);
            void setPosition(sf::Vector2f position);


    private:
        // Variable
            // Basic
                const char *m_name = "skin/ground.png";

            // std
                std::vector<sf::Sprite> m_ListeSprite;

            // SFML
                sf::Sprite m_Sprite;
                sf::Texture m_Texture;
        
        // Function
            void initSprite(void);
            void loadTexture(void);
            void loadSprite(void);
};

#endif