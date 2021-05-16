/**
*** Guillaume LEMONNIER
*** Developpement autonome
*** Tout droits reservé
**/

#if !defined(__MAKESPRITE__)
#define __MAKESPRITE__

#include <SFML/Graphics.hpp>

class Makesprite
{
    public:
        // Constructor / Destructor
            // Constructor
                Makesprite();
                Makesprite(const char *name);

            // Destructor
                ~Makesprite();

        // Accessor
            sf::Sprite getSprite();
            sf::Vector2f getPosition();

        // Function
            void move(sf::Vector2f vector);

    private:
        // Variable
            // basic

            // SFML
                sf::Sprite  m_Sprite;
                sf::Texture m_Texture;
};

#endif