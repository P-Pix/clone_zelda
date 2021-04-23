#if !defined(__LOADER__)
#define __LOADER__

#include <iostream>
#include <SFML/Graphics.hpp>

class Loader
{
    public:
        // Constructor / Destructor
            Loader();
            ~Loader();

        // Function
            sf::Font loadFont(const char *NAME_FONT);
            sf::Texture loadTexture(const char *NAME_IMAGE);
            sf::Sprite loadSprite(const char *NAME, sf::Vector2f VECTOR, sf::Texture *TEXTURE);

    private:
        // Variable
            //iostream

            //SFML
                sf::Texture m_Texture;
                sf::Sprite m_Sprite;
};


#endif