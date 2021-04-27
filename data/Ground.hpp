#if !defined(__GROUND__)
#define __GROUND__

#include <SFML/Graphics.hpp>
#include <iostream>

class Ground
{
    public:
        // Constructor / Destrutor
            Ground();
            Ground(const char *NAME);
            ~Ground();
        
        // Accessor
            sf::Sprite getSprite();
            Ground* getAdress();
        
        // Function
            void setPosition(sf::Vector2f POSITION);


    private:
        // Variable
            // iostream
                const char *m_Name = "skin/ground.png";

            // SFML
                sf::Sprite m_Sprite;
                sf::Texture m_Texture;
        
        // Function
            void initSprite();
            void loadTexture();
            void loadSprite();
};

#endif