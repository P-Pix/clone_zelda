#if !defined(__GROUND__)
#define __GROUND__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Ground
{
    public:
        // Constructor / Destrutor
            Ground();
            Ground(const char *NAME);
            ~Ground();
        
        // Accessor
            std::vector<sf::Sprite> getListSprite();
            sf::Sprite getSprite();
            Ground* getAdress();
        
        // Function
            void setPositionVector(std::vector<sf::Vector2f> vector);
            void setPosition(sf::Vector2f POSITION);


    private:
        // Variable
            // iostream
                std::vector<sf::Sprite> m_ListeSprite;
                const char *m_Name = "skin/ground.png";

            // SFML
                sf::Sprite m_Sprite;
                sf::Texture m_Texture;
        
        // Function
            sf::Sprite getSpritePosition(sf::Vector2f position);
            void initSprite();
            void loadTexture();
            void loadSprite();
};

#endif