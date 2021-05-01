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
            Ground(const char *name);
            ~Ground();
        
        // Accessor
            std::vector<sf::Sprite> getListSprite();
            sf::Sprite getSprite();
            Ground* getAdress();
        
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
            void initSprite();
            void loadTexture();
            void loadSprite();
};

#endif